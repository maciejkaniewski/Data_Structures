#include <gtest/gtest.h>

#include <algorithm>
#include <list.hh>

TEST(ListTest, pushFront) {
  List<int> list;
  list.pushFront(1);
  list.pushFront(2);
  list.pushFront(3);

  GTEST_ASSERT_EQ(list[0], 3);
  GTEST_ASSERT_EQ(list[1], 2);
  GTEST_ASSERT_EQ(list[2], 1);
}

TEST(ListTest, pushBack) {
  List<int> list;
  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);

  GTEST_ASSERT_EQ(list[0], 1);
  GTEST_ASSERT_EQ(list[1], 2);
  GTEST_ASSERT_EQ(list[2], 3);
}

TEST(ListTest, insert) {
  List<int> list;

  list.pushBack(1);
  list.pushBack(2);
  list.insert(3, 1);
  list.insert(4, 0);

  GTEST_ASSERT_EQ(list[0], 4);
  GTEST_ASSERT_EQ(list[1], 1);
  GTEST_ASSERT_EQ(list[2], 3);
  GTEST_ASSERT_EQ(list[3], 2);
}

TEST(ListTest, remove) {
  List<int> list;

  list.pushBack(1);
  list.pushBack(2);
  list.pushBack(3);

  list.remove(2);

  GTEST_ASSERT_EQ(list[0], 1);
  GTEST_ASSERT_EQ(list[1], 3);

  list.remove(1);

  GTEST_ASSERT_EQ(list[0], 3);
}

TEST(ListTest, removeAll) {
  List<int> list;

  list.pushBack(1);
  list.pushBack(7);
  list.pushBack(2);
  list.pushBack(7);
  list.pushBack(3);
  list.pushBack(7);

  list.removeAll(7);

  GTEST_ASSERT_EQ(list[0], 1);
  GTEST_ASSERT_EQ(list[1], 2);
  GTEST_ASSERT_EQ(list[2], 3);
}

TEST(ListTest, Iterator) {
  List<int> list;

  list.pushBack(3);
  list.pushBack(2);
  list.pushBack(1);

  std::sort(list.begin(), list.end());

  GTEST_ASSERT_EQ(list[0], 1);
  GTEST_ASSERT_EQ(list[1], 2);
  GTEST_ASSERT_EQ(list[2], 3);
}

TEST(ListTest, ConstIterator) {
  List<int> list;

  std::array<int, 3> refArray = {3, 55, 1};

  for (auto& element : refArray) {
    list.pushBack(element);
  }

  int index = 0;
  for (auto it = list.constBegin(); it != list.constEnd(); ++it) {
    GTEST_ASSERT_EQ(*it, refArray[index++]);
  }
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}