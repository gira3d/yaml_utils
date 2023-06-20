#ifndef YAML_UTILS_H
#define YAML_UTILS_H

#include <iostream>
#include <regex>
#include <yaml-cpp/yaml.h>

namespace yaml_utils
{
  inline bool open(const std::string filename, YAML::Node& params)
  {
    try
    {
      params = YAML::LoadFile(filename);
    }
    catch (YAML::BadFile)
    {
      return false;
    }
    return true;
  }

  inline bool has(const std::string& p, YAML::Node& params)
  {
    return params[p];
  }

  inline bool failure(const std::string& p)
  {
    std::cerr << "\033[1;33mWARNING: Failed to load " << p << "\033[0m" << std::endl;
    return false;
  }

  template<typename T>
  inline bool get(const std::string& p, const YAML::Node& params, T& val)
  {
    std::string regExprStr(R"(/)");
    std::regex rgx(regExprStr);
    std::smatch smatch;
    std::string base = p;

    YAML::Node node = YAML::Clone(params);

    while (std::regex_search(base, smatch, rgx))
    {
      std::string prefix = smatch.prefix();

      if (!has(prefix, node)) return failure(p);
      else node = node[prefix];
      base = smatch.suffix();
    }

    if (!has(base, node)) return failure(p);
    else val = node[base].as<T>();

    return true;
  }
}

#endif
