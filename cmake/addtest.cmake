macro(addtest NAME)
  add_executable(${NAME} ${ARGN})
  target_link_libaries(${NAME} gtest gtest_main)
  gtest_discover_tests(${NAME}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  )
  set_target_properties(${NAME} PROPERTIES FOLDER tests)
endmacro()

