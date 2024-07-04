#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, InvalidCharactersSpCharSet1) {
  char soundex[5];
  generateSoundex("A$SAM", soundex);
  EXPECT_STREQ(soundex,"A250");
}

TEST(SoudexTestsuite, InvalidCharactersSpCharSet2) {
  char soundex[5];
  generateSoundex("N^GALAND", soundex);
  EXPECT_STREQ(soundex,"N245");
}

TEST(SoudexTestsuite, EmptyCharacter) {
  char soundex[5];
  generateSoundex("", soundex);
  EXPECT_STREQ(soundex,"");
}

TEST(SoudexTestsuite, SingleCharacter) {
  char soundex[5];
  generateSoundex("Z", soundex);
  EXPECT_STREQ(soundex,"Z000");
}

TEST(SoudexTestsuite, AllVowels) {
  char soundex[5];
  generateSoundex("AEIOU", soundex);
  EXPECT_STREQ(soundex,"A000");
}
