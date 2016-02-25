#include "gtest/gtest.h"
#include <utility>


class Foo {
public:
  Foo() = default;
  Foo(const int &j): i(new int(j)) {};

  // move operator "steals" origin value
  // should assure deleting moved object be harmless
  Foo(Foo &&f) noexcept: i(f.i) {
    f.i = nullptr;
  };

  Foo &operator=(Foo &&f) noexcept {
    if (this != &f) {
      int tmp = *f.i;
      i = &tmp;
    };
    return *this;
  };

  int square() {
    return *i * *i;
  };

private:
  int *i;
};


TEST(MoveTest, SomeTest) {
  Foo a = Foo(3);
  auto b = std::move(a);
  EXPECT_EQ(b.square(), 9);

  Foo c;
  c = std::move(b);
  EXPECT_EQ(c.square(), 9);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
