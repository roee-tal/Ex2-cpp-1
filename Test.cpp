#include "Direction.hpp"
#include "Notebook.hpp"
#include "doctest.h"
#include <array>
#include <string>


TEST_CASE("Bad input") {
  ariel::Notebook notebook;
for (int i = 1; i < 20; i++)
	{
		CHECK_THROWS(notebook.erase(0, 0, 99, Direction::Horizontal, i)); 
	}
	CHECK_THROWS(notebook.erase(0, 0, 0, Direction::Horizontal, 101)); 
}


TEST_CASE("Good input") {
  ariel::Notebook notebook;
  CHECK_NOTHROW(notebook.write(0, 0, 0, ariel::Direction::Horizontal, "ariel"));
  CHECK_NOTHROW(notebook.write(1, 1, 0, ariel::Direction::Horizontal, "ariel"));
  CHECK_NOTHROW(notebook.write(1, 1, 1, ariel::Direction::Horizontal, "ariel"));

  CHECK_NOTHROW(notebook.write(1, 1, 0, ariel::Direction::Vertical, "ariel"));
  CHECK_NOTHROW(notebook.write(1, 1, 1, ariel::Direction::Vertical, "ariel"));
  CHECK_NOTHROW(notebook.write(1, 1, 0, ariel::Direction::Vertical, "ariel"));
  CHECK_NOTHROW(notebook.write(1, 1, 0, ariel::Direction::Vertical, "ariel"));
}


TEST_CASE("functions") {
  ariel::Notebook notebook;
 
  SUBCASE("write")
  notebook.write(0, 100, 0, ariel::Direction::Horizontal, "ariel");
  CHECK_THROWS(notebook.write(0, 100, 0, ariel::Direction::Horizontal,"ariel")); 
  notebook.write(0, 100, 0, ariel::Direction::Vertical, "ariel");
  CHECK_THROWS(notebook.write(0, 100, 0, ariel::Direction::Vertical,"ariel"));
   CHECK_THROWS(notebook.write(0, 99, 0, ariel::Direction::Horizontal, "ariel")); 
  CHECK_THROWS(notebook.write(0, 99, 98, ariel::Direction::Horizontal, "ariel")); 


  SUBCASE("read") {
    CHECK(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 5) == "_____");
    notebook.write(0, 0, 0, ariel::Direction::Horizontal, "ariel");
    CHECK(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 5) == "ariel");
    notebook.write(2, 2, 2, ariel::Direction::Horizontal, "~~~");
    CHECK(notebook.read(2, 2, 2, ariel::Direction::Horizontal, 3) == "~~~");
  }

 
  SUBCASE("erase") {
    CHECK(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 5) == "_____");
    notebook.write(0, 0, 0, ariel::Direction::Horizontal, "ariel");
    CHECK(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 5) == "ariel");
    notebook.erase(0, 0, 0, ariel::Direction::Horizontal, 5);
    CHECK(notebook.read(0, 0, 0, ariel::Direction::Horizontal, 5) == "~~~~~");

    CHECK(notebook.read(1, 0, 0, ariel::Direction::Vertical, 5) == "_____");
    notebook.write(1, 0, 0, ariel::Direction::Vertical, "ariel");
    CHECK(notebook.read(1, 0, 0, ariel::Direction::Vertical, 5) == "ariel");
    notebook.erase(1, 0, 0, ariel::Direction::Vertical, 5);
    CHECK(notebook.read(1, 0, 0, ariel::Direction::Vertical, 5) == "~~~~~");
  }

}