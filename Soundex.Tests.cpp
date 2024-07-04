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

TEST(SoudexTestsuite, MaximumCharacters) {
  char soundex[5];
  generateSoundex("abcdefghijklmnopqrstuvwxyzab", soundex);
  EXPECT_STREQ(soundex,"A123");
}

TEST(SoudexTestsuite, AllVowels) {
  char soundex[5];
  generateSoundex("AEIOU", soundex);
  EXPECT_STREQ(soundex,"A000");
}

TEST(SoudexTestsuite, NonMappableCharacters) {
  char soundex[5];
  generateSoundex("147!@#$", soundex);
  EXPECT_STREQ(soundex,"1000");
}

TEST(SoudexTestsuite, MixCharacters) {
  char soundex[5];
  generateSoundex("P1Q2R2S3T4", soundex);
  EXPECT_STREQ(soundex,"P262");
}

TEST(SoudexTestsuite, Normal) {
  char soundex[5];
  generateSoundex("CLEANCODE", soundex);
  EXPECT_STREQ(soundex,"C452");
}

TEST(SoudexTestsuite, NormalMixedCase) {
  char soundex[5];
  generateSoundex("ClEaNcOdE", soundex);
  EXPECT_STREQ(soundex,"C452");
}

TEST(SoudexTestsuite, SameMappingCharacters) {
  char soundex[5];
  generateSoundex("ZBFCGDTLMNR", soundex);
  EXPECT_STREQ(soundex,"Z123");
}

TEST(SoudexTestsuite, VowelSeparation) {
  char soundex[5];
  generateSoundex("Roses", soundex);
  EXPECT_STREQ(soundex,"R220");
}

TEST(SoudexTestsuite, HorWSeparation) {
  char soundex[5];
  generateSoundex("Burroughs", soundex);
  EXPECT_STREQ(soundex,"B620");
  generateSoundex("MIJWKTS", soundex);
  EXPECT_STREQ(soundex,"M232");
}
