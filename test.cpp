#include "pch.h"
#include "CppUnitTest.h"
#include "../main/Fun.h"
#include "../main/Klase.h"
#include "../main/generavimas.h"
#include "../main/struktura.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Struktura, GalutinisTusciasTestPassed) {
	struktura stud;
	EXPECT_EQ(0, stud.Galutinis);
	EXPECT_TRUE(true); //Turi duot teisinga, nes strukturoje Galutinis ir yra 0
}
TEST(Struktura, GalutinisTusciasTestFailed) {
	struktura stud;
	EXPECT_EQ(0, stud.Galutinis);
	EXPECT_FALSE(true); //Turi duot neteisinga, nes strukturoje Galutinis sukuriamas 0
}

// Testas su isvalymu
struct StrukturaTest : testing::Test {
	struktura* stud;

	StrukturaTest() {
		stud = new struktura;
	}

	~StrukturaTest() {
		delete stud;
	}
};

TEST_F(StrukturaTest, GalutinisTuscias) {
	EXPECT_EQ(0, stud->Galutinis);
}

