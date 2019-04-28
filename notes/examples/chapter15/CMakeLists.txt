cmake_minimum_required(VERSION 3.10.1)
project(chapter15notes)
set(CMAKE_CXX_STANDARD 11)

# Test for the GradedActivityV1 class
set(GRADED_ACTIVITY_V1_SRCS GradedActivityV1.cpp)
add_executable(gradedactivitytestv1
    gradedActivityTestV1.cpp
    ${GRADED_ACTIVITY_V1_SRCS})

# Test for the FinalExamV1 class
set(FINAL_EXAM_V1_SRCS 
    ${GRADED_ACTIVITY_V1_SRCS}
    FinalExamV1.cpp)
add_executable(finalexamtestv1
    finalExamTestV1.cpp
    ${FINAL_EXAM_V1_SRCS})

# Test for the GradedActivityV2 class
set(GRADED_ACTIVITY_V2_SRCS GradedActivityV2.cpp)
add_executable(gradedactivitytestv2
    gradedActivityTestV2.cpp
    ${GRADED_ACTIVITY_V2_SRCS})

# Test for the FinalExamV2 class
set(FINAL_EXAM_V2_SRCS 
    ${GRADED_ACTIVITY_V2_SRCS}
    FinalExamV2.cpp)
add_executable(finalexamtestv2
    finalExamTestV2.cpp
    ${FINAL_EXAM_V2_SRCS})

# Test for the CurvedActivity V1 class
set(CURVED_ACTIVITY_V2_SRCS 
    GradedActivityV3.cpp
    CurvedActivity.h)
add_executable(testcurvedactivityv1
    testCurvedActivityV1.cpp
    ${CURVED_ACTIVITY_V2_SRCS})

# Test for the CurvedActivity V1 class
set(PASS_FAIL_EXAM_V1_SRCS
    GradedActivityV3.cpp
    PassFailActivityV1.cpp
    PassFailExamV1.cpp
    CurvedActivity.h)
add_executable(testpassfailexamv1
    testPassFailExamV1.cpp
    ${PASS_FAIL_EXAM_V1_SRCS})