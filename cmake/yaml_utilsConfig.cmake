# - Try to find yaml_utils header files
#
# Once done this will define
#
# YAML_UTILS

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)
set(yaml_utils_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/yaml_utils/include")
set(yaml_utils_LIBRARY "")
