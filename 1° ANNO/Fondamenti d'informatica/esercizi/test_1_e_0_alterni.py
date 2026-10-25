import unittest
from `1 e 0 alterni` import build_alternating_square


class TestAlternatingSquare(unittest.TestCase):
    def test_n_1(self):
        self.assertEqual(build_alternating_square(1), "1")

    def test_n_2(self):
        expected = "1 0\n0 1"
        self.assertEqual(build_alternating_square(2), expected)

    def test_n_3(self):
        expected = "1 0 1\n0 1 0\n1 0 1"
        self.assertEqual(build_alternating_square(3), expected)

    def test_zero_or_negative(self):
        self.assertEqual(build_alternating_square(0), "")
        self.assertEqual(build_alternating_square(-5), "")


if __name__ == '__main__':
    unittest.main()
