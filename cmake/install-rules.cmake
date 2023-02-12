install(
    TARGETS test-exe_exe
    RUNTIME COMPONENT test-exe_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
