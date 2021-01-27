#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "/Users/gvgromov/CLionProjects/algo/globalVar.hpp"
#include "/Users/gvgromov/CLionProjects/algo/quickSort.hpp"

BOOST_AUTO_TEST_CASE(test_order_before_sort)
{
  randomFill(gromov::array, gromov::SIZE);
  bool isUnordered = false;
  for (auto i = 0; i < gromov::SIZE - 1; ++i)
  {
    if(gromov::array[i] > gromov::array[i + 1])
    {
      isUnordered = true;
    }
  }
  if(!isUnordered)
  {
    BOOST_ERROR("Unordered array!");
  }
}

BOOST_AUTO_TEST_CASE(test_order_after_sort, * boost::unit_test::depends_on("test_order_before_sort"))
{
  quickSort(gromov::array, 0, gromov::SIZE);
  for (auto i = 0; i < gromov::SIZE - 1; ++i)
  {
    if(gromov::array[i] > gromov::array[i + 1])
    {
      std::string str("Invalid order after sort, compare between: " + std::to_string(i) + " and " + std::to_string(i + 1)
                      + "\n First value: " + std::to_string(gromov::array[i]) + ", second value: " + std::to_string(gromov::array[i + 1]));
      BOOST_ERROR(str.c_str());
      exit(-1);
    }
  }
}

