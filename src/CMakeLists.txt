add_library(titleRating STATIC titleRating.cpp)
target_include_directories(titleRating PUBLIC ../inc)

add_library(titleRatingCollection STATIC titleRatingCollection.cpp)
target_include_directories(titleRatingCollection PUBLIC ../inc)
target_link_libraries(titleRatingCollection PUBLIC titleRating)