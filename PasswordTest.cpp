#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}
	virtual ~PasswordTest() {}
	virtual void SetUp() {}
	virtual void TearDown() {}
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_leading_same_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZz");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, all_same_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaa");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, no_leading_repeats)
{
	Password my_password;
	int actual = my_password.count_leading_characters("abcd");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, case_sensitive_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Aaaa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeats_only_at_start)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaabbb");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, mixed_case_true)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Hello");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, all_lowercase_no_mixed)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("hello");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, all_uppercase_no_mixed)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("HELLO");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, single_uppercase_is_mixed)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("hellO");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, single_lowercase_is_mixed)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("HELLo");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, unique_single_character)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("a");
	ASSERT_EQ(1u, actual);
}

TEST(PasswordTest, unique_all_same_characters)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("aaaa");
	ASSERT_EQ(1u, actual);
}

TEST(PasswordTest, unique_all_different_characters)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("abcd");
	ASSERT_EQ(4u, actual);
}

TEST(PasswordTest, unique_case_sensitive)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("aA");
	ASSERT_EQ(2u, actual);
}

TEST(PasswordTest, unique_mixed_with_duplicates)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("aabbcc");
	ASSERT_EQ(3u, actual);
}

TEST(PasswordTest, unique_empty_string)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("");
	ASSERT_EQ(0u, actual);
}