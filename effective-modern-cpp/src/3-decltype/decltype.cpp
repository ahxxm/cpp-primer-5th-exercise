#include <iostream>
#include <utility>
#include <vector>
#include "gtest/gtest.h"



void decl() {
  int w = 2;
  decltype(auto) k = w; // c++14 extension
  std::cout << &k << std::endl;

  //  (w) <- expression yields lvalue
  // decltype((w)) <- int&
  // return (w) // returns ref to local variable, undefined.
}

// trail type is not required in C++14
// auto authAndAccess(Container &&c, Index i)->decltype(std::forward<Container>(c)[i]) {


template<typename Container, typename Index>
auto authAndAccess(Container &&c, Index i) {
  // authenticate();
  return std::forward<Container>(c)[i];
};


TEST(MoreClassExerciseTest, SomeTest) {
  decl();
  std::vector<int> ve = {1, 2, 3, 4};
  auto k = authAndAccess(ve, 1);
  EXPECT_EQ(k, 2);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
