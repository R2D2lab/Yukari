/** @file */

#ifndef DOXYGEN_SKIP

#define BOOST_TEST_MODULE "Vector4Test"

#include <boost/qvm/all.hpp>
#include <boost/test/unit_test.hpp>

#include <YukariMaths/Vector4.h>

using namespace boost::qvm;

#define TOL 0.000011f

namespace Yukari
{
namespace Maths
{
  namespace Test
  {
    /* Boost provided functionality */

    BOOST_AUTO_TEST_CASE(Vector4_Addition)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2(4.4f, 6.6f, 7.7f, 8.8f);
      Vector4 v3 = v1 + v2;
      BOOST_CHECK_CLOSE(v3.x(), 5.5f, TOL);
      BOOST_CHECK_CLOSE(v3.y(), 8.8f, TOL);
      BOOST_CHECK_CLOSE(v3.z(), 11.0f, TOL);
      BOOST_CHECK_CLOSE(v3.w(), 13.2f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Subtraction)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2(4.4f, 6.6f, 7.7f, 8.8f);
      Vector4 v3 = v1 - v2;
      BOOST_CHECK_CLOSE(v3.x(), -3.3f, TOL);
      BOOST_CHECK_CLOSE(v3.y(), -4.4f, TOL);
      BOOST_CHECK_CLOSE(v3.z(), -4.4f, TOL);
      BOOST_CHECK_CLOSE(v3.w(), -4.4f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Multiplication_By_Scalar)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2 = v1 * 5.0f;
      BOOST_CHECK_CLOSE(v2.x(), 5.5f, TOL);
      BOOST_CHECK_CLOSE(v2.y(), 11.0f, TOL);
      BOOST_CHECK_CLOSE(v2.z(), 16.5f, TOL);
      BOOST_CHECK_CLOSE(v2.w(), 22.0f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Division_By_Scalar)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2 = v1 / 5.0f;
      BOOST_CHECK_CLOSE(v2.x(), 0.22f, TOL);
      BOOST_CHECK_CLOSE(v2.y(), 0.44f, TOL);
      BOOST_CHECK_CLOSE(v2.z(), 0.66f, TOL);
      BOOST_CHECK_CLOSE(v2.w(), 0.88f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Length)
    {
      Vector4 v(2.0f, 5.0f, 7.0f, 9.0f);
      BOOST_CHECK_CLOSE(boost::qvm::mag(v), 12.61f, 0.01f);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Length2)
    {
      Vector4 v(2.0f, 5.0f, 7.0f, 9.0f);
      BOOST_CHECK_CLOSE(boost::qvm::mag_sqr(v), 159.0f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Normalise)
    {
      Vector4 v(2.0f, 5.0f, 7.0f, 9.0f);
      normalize(v);
      BOOST_CHECK_CLOSE(mag(v), 1.0f, TOL);
      BOOST_CHECK_CLOSE(v.x(), 0.15861f, 0.01f);
      BOOST_CHECK_CLOSE(v.y(), 0.39652f, 0.01f);
      BOOST_CHECK_CLOSE(v.z(), 0.55513f, 0.01f);
      BOOST_CHECK_CLOSE(v.w(), 0.71374f, 0.01f);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Addition_Assignment)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2(4.4f, 6.6f, 7.7f, 8.8f);
      v1 += v2;
      BOOST_CHECK_CLOSE(v1.x(), 5.5f, TOL);
      BOOST_CHECK_CLOSE(v1.y(), 8.8f, TOL);
      BOOST_CHECK_CLOSE(v1.z(), 11.0f, TOL);
      BOOST_CHECK_CLOSE(v1.w(), 13.2f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Subtraction_Assignment)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2(4.4f, 6.6f, 7.7f, 8.8f);
      v1 -= v2;
      BOOST_CHECK_CLOSE(v1.x(), -3.3f, TOL);
      BOOST_CHECK_CLOSE(v1.y(), -4.4f, TOL);
      BOOST_CHECK_CLOSE(v1.z(), -4.4f, TOL);
      BOOST_CHECK_CLOSE(v1.w(), -4.4f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Multiplication_By_Scalar_Assignment)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      v1 *= 5.0f;
      BOOST_CHECK_CLOSE(v1.x(), 5.5f, TOL);
      BOOST_CHECK_CLOSE(v1.y(), 11.0f, TOL);
      BOOST_CHECK_CLOSE(v1.z(), 16.5f, TOL);
      BOOST_CHECK_CLOSE(v1.w(), 22.0f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Division_By_Scalar_Assignment)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      v1 /= 5.0f;
      BOOST_CHECK_CLOSE(v1.x(), 0.22f, TOL);
      BOOST_CHECK_CLOSE(v1.y(), 0.44f, TOL);
      BOOST_CHECK_CLOSE(v1.z(), 0.66f, TOL);
      BOOST_CHECK_CLOSE(v1.w(), 0.88f, TOL);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Equality)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2(4.4f, 6.6f, 7.7f, 8.8f);
      Vector4 v3(1.1f, 2.2f, 3.3f, 4.4f);
      BOOST_CHECK(v1 == v3);
      BOOST_CHECK(!(v1 == v2));
      BOOST_CHECK(!(v2 == v3));
    }

    BOOST_AUTO_TEST_CASE(Vector4_Inequality)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2(4.4f, 6.6f, 7.7f, 8.8f);
      Vector4 v3(1.1f, 2.2f, 3.3f, 4.4f);
      BOOST_CHECK(!(v1 != v3));
      BOOST_CHECK(v1 != v2);
      BOOST_CHECK(v2 != v3);
    }

    /* Vector4 functionality */

    BOOST_AUTO_TEST_CASE(Vector4_Init_Empty)
    {
      Vector4 v;
      BOOST_CHECK_EQUAL(v.x(), 0.0f);
      BOOST_CHECK_EQUAL(v.y(), 0.0f);
      BOOST_CHECK_EQUAL(v.z(), 0.0f);
      BOOST_CHECK_EQUAL(v.w(), 1.0f);
      BOOST_CHECK_EQUAL(boost::qvm::X(v), 0.0f);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Init_Value)
    {
      Vector4 v(1.1f, 2.2f, 3.3f, 4.4f);
      BOOST_CHECK_EQUAL(v.x(), 1.1f);
      BOOST_CHECK_EQUAL(v.y(), 2.2f);
      BOOST_CHECK_EQUAL(v.z(), 3.3f);
      BOOST_CHECK_EQUAL(v.w(), 4.4f);
    }

    BOOST_AUTO_TEST_CASE(Vector4_Init_Copy)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Vector4 v2(v1);
      BOOST_CHECK_EQUAL(v2.x(), 1.1f);
      BOOST_CHECK_EQUAL(v2.y(), 2.2f);
      BOOST_CHECK_EQUAL(v2.z(), 3.3f);
      BOOST_CHECK_EQUAL(v2.w(), 4.4f);
    }

    BOOST_AUTO_TEST_CASE(Vector4_ToEigen)
    {
      Vector4 v1(1.1f, 2.2f, 3.3f, 4.4f);
      Eigen::Vector4f v2 = v1.toEigen();
      BOOST_CHECK_EQUAL(v2.x(), 1.1f);
      BOOST_CHECK_EQUAL(v2.y(), 2.2f);
      BOOST_CHECK_EQUAL(v2.z(), 3.3f);
      BOOST_CHECK_EQUAL(v2.w(), 4.4f);
    }

    /* BaseMathType functionality */

    BOOST_AUTO_TEST_CASE(Vector4_Stream_Out)
    {
      Vector4 v(1.1f, 2.2f, 3.3f, 4.4f);
      std::stringstream str;
      str << v;
      BOOST_CHECK_EQUAL("[1.1, 2.2, 3.3, 4.4]", str.str());
    }

    BOOST_AUTO_TEST_CASE(Vector4_Stream_In)
    {
      std::stringstream str("[1.1, 2.2, 3.3, 4.4]");
      Vector4 v;
      str >> v;
      BOOST_CHECK(v == Vector4(1.1f, 2.2f, 3.3f, 4.4f));
    }
  }
}
}

#endif
