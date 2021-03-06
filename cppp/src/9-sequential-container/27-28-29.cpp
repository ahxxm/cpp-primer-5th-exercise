#include <forward_list>
#include <string>
#include <vector>
#include "gtest/gtest.h"

// 27
std::forward_list<int> &remove_odd_from_forward_list(std::forward_list<int> &lst) {
  // the one before begin
  auto prev = lst.before_begin();
  auto iter = lst.begin();

  // avoid store .end()
  // because it's invalidated
  while (iter != lst.end()) {
    if (*iter % 2) {
      iter = lst.erase_after(prev);
    } else {
      prev = iter;
      iter++;
    }
  }

  return lst;
}

// 28: a function
// param: forward_list<string> + string1 + string2
// if (find string 1){ insert string2 after string1 }
// else { insert string2 at the end }

typedef std::forward_list<std::string> sfs;
sfs &find_and_insert(sfs &fl, const std::string &st1, const std::string &st2) {
  // insert only once
  auto prev = fl.before_begin();

  for (auto iter = fl.begin(); iter != fl.end(); prev = iter++) {
    if (*iter == st1) {
      fl.insert_after(iter, st2);
      return fl;
    }
  }

  fl.insert_after(prev, st2);
  return fl;
}

TEST(ForwardListTest, SomeTest) {
  std::forward_list<int> sample_lst = {1, 2, 3, 4, 5};
  auto new_lst = remove_odd_from_forward_list(sample_lst);

  std::forward_list<std::string> ls = {"string1", "aa", "bb"};
  std::forward_list<std::string> ls_e = {"string1", "aa", "cc", "bb"};
  auto ls_i = find_and_insert(ls, "aa", "cc");
  EXPECT_EQ(ls_i, ls_e);

  std::forward_list<std::string> ls2 = {"string1", "aa", "bb"};
  std::forward_list<std::string> ls2_e = {"string1", "aa", "bb", "d"};
  auto ls2_i = find_and_insert(ls2, "cc", "d");
  EXPECT_EQ(ls2_i, ls2_e);
}

TEST(VectorResizeTest, SomeOtherTest) {
  // 29:
  std::vector<int> va(25, 10);
  EXPECT_EQ(static_cast<int>(va.size()), 25);

  va.resize(100);
  EXPECT_EQ(va[99], 0);

  va.resize(10);
  EXPECT_EQ(va[9], 10);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
