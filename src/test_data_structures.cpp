#include <gtest/gtest.h>
#include <list.hh>

TEST(list, push) {
  List<int> list;
  list.pushFront(1);
  list.pushFront(2);

  GTEST_ASSERT_EQ(list[0], 3);
  GTEST_ASSERT_EQ(list[1], 1);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}