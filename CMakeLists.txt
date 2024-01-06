cmake_minimum_required(VERSION 3.18)

project(Server_vedomostna_hra)

set(CMAKE_CXX_STANDARD 17)

add_executable(server
        main_server.cpp
        server.cpp

        QuestionManager/QuestionsManager.cpp
        QuestionManager/Question.cpp
)

target_link_libraries(server pthread)


