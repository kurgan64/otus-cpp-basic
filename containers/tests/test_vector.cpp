#include <gtest/gtest.h>

#include "my_vector.h"

TEST(vector, DefaultConstructor) {
  MyVector<int> vec;
  const size_t zeroSize = 0;
  ASSERT_EQ(vec.size(), zeroSize);
}
TEST(vector, PushBback) {
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }

  ASSERT_EQ(vec.size(), count);
}
TEST(vector, Index){
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  ASSERT_EQ(vec[0], 0);
  ASSERT_EQ(vec[9], 9);
}
TEST(vector, InsertFront){
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  vec.insert(0, 10);
  ASSERT_EQ(vec.size(), 11);
  ASSERT_EQ(vec[0],10);
}
TEST(vector, InsertBack) {
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  vec.insert(10, 30);
  ASSERT_EQ(vec.size(), 11);
  ASSERT_EQ(vec[10], 30);
}
TEST(vector, InsertMiddle) {
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  vec.insert(vec.size() / 2, 20);
  ASSERT_EQ(vec.size(), 11);
  ASSERT_EQ(vec[5], 20);
}
TEST(vector, InsertOutOfRange){
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  
  ASSERT_THROW(vec.insert(12,50), std::out_of_range);
}
TEST(vector, EraseFront){
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  vec.erase(0);

  ASSERT_EQ(vec.size(), 9);
  ASSERT_EQ(vec[0], 1);
}
TEST(vector, EraseMiddle) {
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  vec.erase(vec.size()/2);

  ASSERT_EQ(vec.size(), 9);
  ASSERT_EQ(vec[5], 6);
}
TEST(vector, EraseBack) {
  const int count = 10;
  MyVector<int> vec;
  for (size_t i = 0; i < count; i++) {
    vec.push_back(i);
  }
  vec.erase(9);

  ASSERT_EQ(vec.size(), 9);
}
TEST(vector, CopyConstructor) {
  const int count = 10;
  MyVector<int> vec1;
  for (size_t i = 0; i < count; i++) {
    vec1.push_back(i);
  }
  MyVector vec2 = vec1;
  ASSERT_GE(&vec1, &vec2);
  ASSERT_EQ(vec1.size(), vec2.size());
  for (size_t i = 0; i < count; i++) {
    ASSERT_EQ(vec1[i], vec2[i]);
  }
}

// int main(int argc, char** argv) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }