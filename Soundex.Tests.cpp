#include <gtest/gtest.h>
#include "Soundex.h"

typedef struct
{
    const char *string;
    const char *code;
}stringCodeMap;

stringCodeMap StringCodeMap_st[] =
{
    {   "A$SAM",                            "A250" },
    {   "N^GALAND",                         "N245" },
    {   "",                                 ""     },
    {   "Z",                                "Z000" },
    {   "abcdefghijklmnopqrstuvwxyzab",     "A123" },
    {   "AEIOU",                            "A000" },
    {   "147!@#$",                          "1000" },
    {   "P1Q2R2S3T4",                       "P262" },
    {   "CLEANCODE",                        "C452" },
    {   "ClEaNcOdE",                        "C452" },
    {   "ZBFCGDTLMNR",                      "Z123" },
    {   "Roses",                            "R220" },
    {   "Rosas",                            "R220" },
    {   "Rosos",                            "R220" },
    {   "Rosus",                            "R220" },
    {   "Rosis",                            "R220" },
    {   "Rosys",                            "R220" },
    {   "Burroughs",                        "B620" },
    {   "MIJWKTS",                          "M232" },
};


TEST(SoudexTestsuite, ValidateMappings) {
  char soundex[5];

  for(int i = 0; i < 19; i++)
  {
      generateSoundex(StringCodeMap_st[i].string, soundex);
      EXPECT_STREQ(soundex, StringCodeMap_st[i].code);
  }
}
