function(add_day day)
    add_executable(${day} ${day}.cc main.cc)
    target_compile_features(${day} PRIVATE cxx_std_20)
    target_include_directories(${day} PRIVATE . ${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(${day} PRIVATE benchmark fmt::fmt)
endfunction()

configure_file(Config.hh.in Config.hh)
