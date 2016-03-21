#include "gtest/gtest.h"
#include <regex>
#include <string>



TEST(RegexTest, SomeTest) {
  // find ei, that follow a char other than c
  std::string re_pattern("[^c]ei");
  std::string text("ooaeiuuuu");
  std::regex r(re_pattern);

  std::smatch results;
  auto result = std::regex_search(text, results, r);
  EXPECT_EQ(result, true);
  EXPECT_EQ(results.str(), "aei");

  std::smatch no_results;
  std::string no_result_text("uiiui");
  auto no_result = std::regex_search(no_result_text, no_results, r);
  EXPECT_EQ(no_result, false);
  EXPECT_EQ(no_results.str(), "");

}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
