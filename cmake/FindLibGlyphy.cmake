# - Try to find libGlyphy
# Once done this will define
#  LIBGLYPHY_FOUND - System has libglyphy
#  LIBGLYPHY_INCLUDE_DIRS - The GLyphy include directories
#  LIBGLYPHY_LIBRARIES - The libraries needed to use libglyphy
#  LIBGLYPHY_DEFINITIONS - Compiler switches required for using libglyphy

find_path(LIBGLYPHY_INCLUDE_DIR NAMES glyphy.h HINTS deps/glyphy/src)

find_library(LIBGLYPHY_LIBRARY NAMES libglyphy.a HINTS deps/glyphy/src/.libs)

set(LIBGLYPHY_LIBRARIES
    ${LIBGLYPHY_LIBRARY}
)
set(LIBGLYPHY_INCLUDE_DIRS ${LIBGLYPHY_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBGLYPHY_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(LibGlyphy DEFAULT_MSG
                                  LIBGLYPHY_LIBRARY LIBGLYPHY_INCLUDE_DIR)

mark_as_advanced(LIBGLYPHY_INCLUDE_DIR LIBGLYPHY_LIBRARY )

