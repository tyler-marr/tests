/*
########################################################################
# This file is part of tests.srec, a simple testsuite for WRAMP
#
# Copyright (C) 2019 The University of Waikato, Hamilton, New Zealand.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
########################################################################
*/


// These tests were written manually and aim to test most behaviours
// for arithmetic instructions, including some edge cases.
test_normal(0, 0, add, 0);
test_normal(2, 2, add, 4);
test_normal(-2, 2, add, 0);
test_normal(2, -2, add, 0);
test_overflow(0x7FFFFFFF, 0x7FFFFFFF, add);
test_overflow((int)0x80000000, (int)0x80000000, add);
test_normal(0x7FFFFFFF, (int)0x80000001, add, 0);
test_normal((int)0x80000001, 0x7FFFFFFF, add, 0);

test_normal(0, 0, addu, 0);
test_normal(2, 2, addu, 4);
test_overflow((int)0xFFFFFFFF, (int)0xFFFFFFFF, addu);

test_normal(0, 0, sub, 0);
test_normal(4, 2, sub, 2);
test_normal(4, 4, sub, 0);
test_normal(4, 8, sub, -4);
test_normal(4, -4, sub, 8);
test_normal(-4, 4, sub, -8);
test_normal(-4, -4, sub, 0);
test_normal(0x7F000000, 0x7FFFFFFF, sub, (int)0xFF000001);
test_normal((int)0xFFFFFFFF, (int)0xFF000000, sub, 0x00FFFFFF);
test_overflow(0x7FFFFFFF, (int)0xFFFFFFFF, sub);
test_overflow((int)0x80000000, 0x0000000F, sub);

test_normal(0, 0, subu, 0);
test_normal(4, 4, subu, 0);
test_overflow(4, 8, subu);
test_normal(0xFFFFFFF, 0xFFFFFFF, subu, 0);
test_overflow(0x0FFFFFF, 0xFFFFFFF, subu);

test_normal(4, 4, div, 1);
test_overflow(4, 0, div);
test_normal(5, 2, div, 2);
test_normal(-4, -4, div, 1);
test_overflow(-4, 0, div);
test_normal(-5, -2, div, 2);
test_normal(5, -2, div, -2);
test_normal(-5, 2, div, -2);

test_normal(4, 4, rem, 0);
test_overflow(4, 0, rem);
test_normal(5, 2, rem, 1);
test_normal(-4, -4, rem, 0);
test_overflow(-4, 0, rem);
test_normal(-5, -2, rem, -1);
test_normal(5, -2, rem, 1);
test_normal(-5, 2, rem, -1);

test_normal(4, 4, divu, 1);
test_overflow(4, 0, divu);
test_normal(5, 2, divu, 2);

test_normal(4, 4, remu, 0);
test_overflow(4, 0, remu);
test_normal(5, 2, remu, 1);

test_normal(0, 0, mult, 0);
test_normal(4, 4, mult, 16);
test_overflow(0x7FFFFFFF, 2, mult);
test_normal(-4, 0, mult, 0);
test_normal(0, -4, mult, 0);
test_normal(-4, -4, mult, 16);
test_normal(4, -4, mult, -16);
test_normal(-4, 4, mult, -16);
test_overflow(0x7FFFFFFF, -2, mult);
test_overflow((int)0x80000000, 2, mult);
test_overflow((int)0x80000000, (int)0x80000000, mult);

test_normal(0, 0, multu, 0);
test_normal(4, 4, multu, 16);
test_overflow((int)0xFFFFFFFF, 2, multu);

test_overflow(INT_MIN, -1, div);
test_overflow(INT_MIN, -1, rem);
test_overflow(INT_MIN, -1, mult);
test_normal(INT_MIN, -1, divu, 0); // (uint)INT_MIN / UINT_MAX 

test_normal(INT_MIN + 1, 1, div, INT_MIN + 1);
test_normal(INT_MIN + 1, 1, rem, 0);
test_normal(INT_MIN + 1, 1, mult, INT_MIN + 1);
test_normal(1, INT_MIN, div, 0);
test_normal(1, INT_MIN, rem, 1);
test_normal(1, INT_MIN, mult, INT_MIN);

test_overflow((INT_MIN/2), 5, mult);

test_normal(INT_MIN, 1, div, INT_MIN);
test_normal(INT_MIN, 1, rem, 0);
test_normal(INT_MIN, 1, mult, INT_MIN);

test_normal(INT_MAX, -1, div, -INT_MAX);
test_normal(INT_MAX, -1, rem, 0);
test_normal(INT_MAX, -1, mult, -INT_MAX);

test_normal(0, -1, div, 0);
test_normal(-1, -1, div, 1);
test_normal(2, -1, div, -2);
test_normal(2, -1, divu, 0); // 2 / UINT_MAX 
test_normal(-1, 1, div, -1);
test_normal((int)UINT_MAX, 1, divu, (int)UINT_MAX);

// These tests were generated automatically and aim to test every
// combination of positive and negative values to arithmetic and test instructions
test_normal((int)0x5, (int)0x2, add , (int)0x7);
test_normal((int)0x5, (int)0xfffffffe, add , (int)0x3);
test_normal((int)0xfffffffb, (int)0x2, add , (int)0xfffffffd);
test_normal((int)0xfffffffb, (int)0xfffffffe, add , (int)0xfffffff9);
test_normal((int)0x2, (int)0x5, add , (int)0x7);
test_normal((int)0x2, (int)0xfffffffb, add , (int)0xfffffffd);
test_normal((int)0xfffffffe, (int)0x5, add , (int)0x3);
test_normal((int)0xfffffffe, (int)0xfffffffb, add , (int)0xfffffff9);
test_normal((int)0x0, (int)0x5, add , (int)0x5);
test_normal((int)0x2, (int)0x0, add , (int)0x2);
test_normal((int)0x0, (int)0x0, add , (int)0x0);
test_normal((int)0x2, (int)0x2, add , (int)0x4);
test_overflow((int)0x7ffffff0, (int)0x7fffffff, add );
test_overflow((int)0x7fffffff, (int)0x7ffffff0, add );
test_normal((int)0x8fffffff, (int)0xffffffff, add , (int)0x8ffffffe);
test_overflow((int)0x80000000, (int)0xffffffff, add );
test_normal((int)0x5, (int)0x2, addu, (int)0x7);
test_overflow((int)0x5, (int)0xfffffffe, addu);
test_normal((int)0xfffffffb, (int)0x2, addu, (int)0xfffffffd);
test_overflow((int)0xfffffffb, (int)0xfffffffe, addu);
test_normal((int)0x2, (int)0x5, addu, (int)0x7);
test_normal((int)0x2, (int)0xfffffffb, addu, (int)0xfffffffd);
test_overflow((int)0xfffffffe, (int)0x5, addu);
test_overflow((int)0xfffffffe, (int)0xfffffffb, addu);
test_normal((int)0x0, (int)0x5, addu, (int)0x5);
test_normal((int)0x2, (int)0x0, addu, (int)0x2);
test_normal((int)0x0, (int)0x0, addu, (int)0x0);
test_normal((int)0x2, (int)0x2, addu, (int)0x4);
test_normal((int)0x7ffffff0, (int)0x7fffffff, addu, (int)0xffffffef);
test_normal((int)0x7fffffff, (int)0x7ffffff0, addu, (int)0xffffffef);
test_overflow((int)0x8fffffff, (int)0xffffffff, addu);
test_overflow((int)0x80000000, (int)0xffffffff, addu);
test_normal((int)0x5, (int)0x2, sub , (int)0x3);
test_normal((int)0x5, (int)0xfffffffe, sub , (int)0x7);
test_normal((int)0xfffffffb, (int)0x2, sub , (int)0xfffffff9);
test_normal((int)0xfffffffb, (int)0xfffffffe, sub , (int)0xfffffffd);
test_normal((int)0x2, (int)0x5, sub , (int)0xfffffffd);
test_normal((int)0x2, (int)0xfffffffb, sub , (int)0x7);
test_normal((int)0xfffffffe, (int)0x5, sub , (int)0xfffffff9);
test_normal((int)0xfffffffe, (int)0xfffffffb, sub , (int)0x3);
test_normal((int)0x0, (int)0x5, sub , (int)0xfffffffb);
test_normal((int)0x2, (int)0x0, sub , (int)0x2);
test_normal((int)0x0, (int)0x0, sub , (int)0x0);
test_normal((int)0x2, (int)0x2, sub , (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sub , (int)0xfffffff1);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sub , (int)0xf);
test_normal((int)0x8fffffff, (int)0xffffffff, sub , (int)0x90000000);
test_normal((int)0x80000000, (int)0xffffffff, sub , (int)0x80000001);
test_normal((int)0x5, (int)0x2, subu, (int)0x3);
test_overflow((int)0x5, (int)0xfffffffe, subu);
test_normal((int)0xfffffffb, (int)0x2, subu, (int)0xfffffff9);
test_overflow((int)0xfffffffb, (int)0xfffffffe, subu);
test_overflow((int)0x2, (int)0x5, subu);
test_overflow((int)0x2, (int)0xfffffffb, subu);
test_normal((int)0xfffffffe, (int)0x5, subu, (int)0xfffffff9);
test_normal((int)0xfffffffe, (int)0xfffffffb, subu, (int)0x3);
test_overflow((int)0x0, (int)0x5, subu);
test_normal((int)0x2, (int)0x0, subu, (int)0x2);
test_normal((int)0x0, (int)0x0, subu, (int)0x0);
test_normal((int)0x2, (int)0x2, subu, (int)0x0);
test_overflow((int)0x7ffffff0, (int)0x7fffffff, subu);
test_normal((int)0x7fffffff, (int)0x7ffffff0, subu, (int)0xf);
test_overflow((int)0x8fffffff, (int)0xffffffff, subu);
test_overflow((int)0x80000000, (int)0xffffffff, subu);
test_normal((int)0x5, (int)0x2, or , (int)0x7);
test_normal((int)0x5, (int)0xfffffffe, or , (int)0xffffffff);
test_normal((int)0xfffffffb, (int)0x2, or , (int)0xfffffffb);
test_normal((int)0xfffffffb, (int)0xfffffffe, or , (int)0xffffffff);
test_normal((int)0x2, (int)0x5, or , (int)0x7);
test_normal((int)0x2, (int)0xfffffffb, or , (int)0xfffffffb);
test_normal((int)0xfffffffe, (int)0x5, or , (int)0xffffffff);
test_normal((int)0xfffffffe, (int)0xfffffffb, or , (int)0xffffffff);
test_normal((int)0x0, (int)0x5, or , (int)0x5);
test_normal((int)0x2, (int)0x0, or , (int)0x2);
test_normal((int)0x0, (int)0x0, or , (int)0x0);
test_normal((int)0x2, (int)0x2, or , (int)0x2);
test_normal((int)0x7ffffff0, (int)0x7fffffff, or , (int)0x7fffffff);
test_normal((int)0x7fffffff, (int)0x7ffffff0, or , (int)0x7fffffff);
test_normal((int)0x8fffffff, (int)0xffffffff, or , (int)0xffffffff);
test_normal((int)0x80000000, (int)0xffffffff, or , (int)0xffffffff);
test_normal((int)0x5, (int)0x2, and , (int)0x0);
test_normal((int)0x5, (int)0xfffffffe, and , (int)0x4);
test_normal((int)0xfffffffb, (int)0x2, and , (int)0x2);
test_normal((int)0xfffffffb, (int)0xfffffffe, and , (int)0xfffffffa);
test_normal((int)0x2, (int)0x5, and , (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, and , (int)0x2);
test_normal((int)0xfffffffe, (int)0x5, and , (int)0x4);
test_normal((int)0xfffffffe, (int)0xfffffffb, and , (int)0xfffffffa);
test_normal((int)0x0, (int)0x5, and , (int)0x0);
test_normal((int)0x2, (int)0x0, and , (int)0x0);
test_normal((int)0x0, (int)0x0, and , (int)0x0);
test_normal((int)0x2, (int)0x2, and , (int)0x2);
test_normal((int)0x7ffffff0, (int)0x7fffffff, and , (int)0x7ffffff0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, and , (int)0x7ffffff0);
test_normal((int)0x8fffffff, (int)0xffffffff, and , (int)0x8fffffff);
test_normal((int)0x80000000, (int)0xffffffff, and , (int)0x80000000);
test_normal((int)0x5, (int)0x2, xor , (int)0x7);
test_normal((int)0x5, (int)0xfffffffe, xor , (int)0xfffffffb);
test_normal((int)0xfffffffb, (int)0x2, xor , (int)0xfffffff9);
test_normal((int)0xfffffffb, (int)0xfffffffe, xor , (int)0x5);
test_normal((int)0x2, (int)0x5, xor , (int)0x7);
test_normal((int)0x2, (int)0xfffffffb, xor , (int)0xfffffff9);
test_normal((int)0xfffffffe, (int)0x5, xor , (int)0xfffffffb);
test_normal((int)0xfffffffe, (int)0xfffffffb, xor , (int)0x5);
test_normal((int)0x0, (int)0x5, xor , (int)0x5);
test_normal((int)0x2, (int)0x0, xor , (int)0x2);
test_normal((int)0x0, (int)0x0, xor , (int)0x0);
test_normal((int)0x2, (int)0x2, xor , (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, xor , (int)0xf);
test_normal((int)0x7fffffff, (int)0x7ffffff0, xor , (int)0xf);
test_normal((int)0x8fffffff, (int)0xffffffff, xor , (int)0x70000000);
test_normal((int)0x80000000, (int)0xffffffff, xor , (int)0x7fffffff);
test_normal((int)0x5, (int)0x2, sll , (int)0x14);
test_normal((int)0x5, (int)0xfffffffe, sll , (int)0x40000000);
test_normal((int)0xfffffffb, (int)0x2, sll , (int)0xffffffec);
test_normal((int)0xfffffffb, (int)0xfffffffe, sll , (int)0xc0000000);
test_normal((int)0x2, (int)0x5, sll , (int)0x40);
test_normal((int)0x2, (int)0xfffffffb, sll , (int)0x10000000);
test_normal((int)0xfffffffe, (int)0x5, sll , (int)0xffffffc0);
test_normal((int)0xfffffffe, (int)0xfffffffb, sll , (int)0xf0000000);
test_normal((int)0x0, (int)0x5, sll , (int)0x0);
test_normal((int)0x2, (int)0x0, sll , (int)0x2);
test_normal((int)0x0, (int)0x0, sll , (int)0x0);
test_normal((int)0x2, (int)0x2, sll , (int)0x8);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sll , (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sll , (int)0xffff0000);
test_normal((int)0x8fffffff, (int)0xffffffff, sll , (int)0x80000000);
test_normal((int)0x80000000, (int)0xffffffff, sll , (int)0x0);
test_normal((int)0x5, (int)0x2, srl , (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, srl , (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, srl , (int)0x3ffffffe);
test_normal((int)0xfffffffb, (int)0xfffffffe, srl , (int)0x3);
test_normal((int)0x2, (int)0x5, srl , (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, srl , (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, srl , (int)0x7ffffff);
test_normal((int)0xfffffffe, (int)0xfffffffb, srl , (int)0x1f);
test_normal((int)0x0, (int)0x5, srl , (int)0x0);
test_normal((int)0x2, (int)0x0, srl , (int)0x2);
test_normal((int)0x0, (int)0x0, srl , (int)0x0);
test_normal((int)0x2, (int)0x2, srl , (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, srl , (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, srl , (int)0x7fff);
test_normal((int)0x8fffffff, (int)0xffffffff, srl , (int)0x1);
test_normal((int)0x80000000, (int)0xffffffff, srl , (int)0x1);
test_normal((int)0x5, (int)0x2, sra , (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, sra , (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, sra , (int)0xfffffffe);
test_normal((int)0xfffffffb, (int)0xfffffffe, sra , (int)0xffffffff);
test_normal((int)0x2, (int)0x5, sra , (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, sra , (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, sra , (int)0xffffffff);
test_normal((int)0xfffffffe, (int)0xfffffffb, sra , (int)0xffffffff);
test_normal((int)0x0, (int)0x5, sra , (int)0x0);
test_normal((int)0x2, (int)0x0, sra , (int)0x2);
test_normal((int)0x0, (int)0x0, sra , (int)0x0);
test_normal((int)0x2, (int)0x2, sra , (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sra , (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sra , (int)0x7fff);
test_normal((int)0x8fffffff, (int)0xffffffff, sra , (int)0xffffffff);
test_normal((int)0x80000000, (int)0xffffffff, sra , (int)0xffffffff);
test_normal((int)0x5, (int)0x2, slt , (int)0x0);
test_normal((int)0x5, (int)0xfffffffe, slt , (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, slt , (int)0x1);
test_normal((int)0xfffffffb, (int)0xfffffffe, slt , (int)0x1);
test_normal((int)0x2, (int)0x5, slt , (int)0x1);
test_normal((int)0x2, (int)0xfffffffb, slt , (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, slt , (int)0x1);
test_normal((int)0xfffffffe, (int)0xfffffffb, slt , (int)0x0);
test_normal((int)0x0, (int)0x5, slt , (int)0x1);
test_normal((int)0x2, (int)0x0, slt , (int)0x0);
test_normal((int)0x0, (int)0x0, slt , (int)0x0);
test_normal((int)0x2, (int)0x2, slt , (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, slt , (int)0x1);
test_normal((int)0x7fffffff, (int)0x7ffffff0, slt , (int)0x0);
test_normal((int)0x8fffffff, (int)0xffffffff, slt , (int)0x1);
test_normal((int)0x80000000, (int)0xffffffff, slt , (int)0x1);
test_normal((int)0x5, (int)0x2, sle , (int)0x0);
test_normal((int)0x5, (int)0xfffffffe, sle , (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, sle , (int)0x1);
test_normal((int)0xfffffffb, (int)0xfffffffe, sle , (int)0x1);
test_normal((int)0x2, (int)0x5, sle , (int)0x1);
test_normal((int)0x2, (int)0xfffffffb, sle , (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, sle , (int)0x1);
test_normal((int)0xfffffffe, (int)0xfffffffb, sle , (int)0x0);
test_normal((int)0x0, (int)0x5, sle , (int)0x1);
test_normal((int)0x2, (int)0x0, sle , (int)0x0);
test_normal((int)0x0, (int)0x0, sle , (int)0x1);
test_normal((int)0x2, (int)0x2, sle , (int)0x1);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sle , (int)0x1);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sle , (int)0x0);
test_normal((int)0x8fffffff, (int)0xffffffff, sle , (int)0x1);
test_normal((int)0x80000000, (int)0xffffffff, sle , (int)0x1);
test_normal((int)0x5, (int)0x2, sgt , (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, sgt , (int)0x1);
test_normal((int)0xfffffffb, (int)0x2, sgt , (int)0x0);
test_normal((int)0xfffffffb, (int)0xfffffffe, sgt , (int)0x0);
test_normal((int)0x2, (int)0x5, sgt , (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, sgt , (int)0x1);
test_normal((int)0xfffffffe, (int)0x5, sgt , (int)0x0);
test_normal((int)0xfffffffe, (int)0xfffffffb, sgt , (int)0x1);
test_normal((int)0x0, (int)0x5, sgt , (int)0x0);
test_normal((int)0x2, (int)0x0, sgt , (int)0x1);
test_normal((int)0x0, (int)0x0, sgt , (int)0x0);
test_normal((int)0x2, (int)0x2, sgt , (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sgt , (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sgt , (int)0x1);
test_normal((int)0x8fffffff, (int)0xffffffff, sgt , (int)0x0);
test_normal((int)0x80000000, (int)0xffffffff, sgt , (int)0x0);
test_normal((int)0x5, (int)0x2, sge , (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, sge , (int)0x1);
test_normal((int)0xfffffffb, (int)0x2, sge , (int)0x0);
test_normal((int)0xfffffffb, (int)0xfffffffe, sge , (int)0x0);
test_normal((int)0x2, (int)0x5, sge , (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, sge , (int)0x1);
test_normal((int)0xfffffffe, (int)0x5, sge , (int)0x0);
test_normal((int)0xfffffffe, (int)0xfffffffb, sge , (int)0x1);
test_normal((int)0x0, (int)0x5, sge , (int)0x0);
test_normal((int)0x2, (int)0x0, sge , (int)0x1);
test_normal((int)0x0, (int)0x0, sge , (int)0x1);
test_normal((int)0x2, (int)0x2, sge , (int)0x1);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sge , (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sge , (int)0x1);
test_normal((int)0x8fffffff, (int)0xffffffff, sge , (int)0x0);
test_normal((int)0x80000000, (int)0xffffffff, sge , (int)0x0);
test_normal((int)0x5, (int)0x2, seq , (int)0x0);
test_normal((int)0x5, (int)0xfffffffe, seq , (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, seq , (int)0x0);
test_normal((int)0xfffffffb, (int)0xfffffffe, seq , (int)0x0);
test_normal((int)0x2, (int)0x5, seq , (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, seq , (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, seq , (int)0x0);
test_normal((int)0xfffffffe, (int)0xfffffffb, seq , (int)0x0);
test_normal((int)0x0, (int)0x5, seq , (int)0x0);
test_normal((int)0x2, (int)0x0, seq , (int)0x0);
test_normal((int)0x0, (int)0x0, seq , (int)0x1);
test_normal((int)0x2, (int)0x2, seq , (int)0x1);
test_normal((int)0x7ffffff0, (int)0x7fffffff, seq , (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, seq , (int)0x0);
test_normal((int)0x8fffffff, (int)0xffffffff, seq , (int)0x0);
test_normal((int)0x80000000, (int)0xffffffff, seq , (int)0x0);
test_normal((int)0x5, (int)0x2, sne , (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, sne , (int)0x1);
test_normal((int)0xfffffffb, (int)0x2, sne , (int)0x1);
test_normal((int)0xfffffffb, (int)0xfffffffe, sne , (int)0x1);
test_normal((int)0x2, (int)0x5, sne , (int)0x1);
test_normal((int)0x2, (int)0xfffffffb, sne , (int)0x1);
test_normal((int)0xfffffffe, (int)0x5, sne , (int)0x1);
test_normal((int)0xfffffffe, (int)0xfffffffb, sne , (int)0x1);
test_normal((int)0x0, (int)0x5, sne , (int)0x1);
test_normal((int)0x2, (int)0x0, sne , (int)0x1);
test_normal((int)0x0, (int)0x0, sne , (int)0x0);
test_normal((int)0x2, (int)0x2, sne , (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sne , (int)0x1);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sne , (int)0x1);
test_normal((int)0x8fffffff, (int)0xffffffff, sne , (int)0x1);
test_normal((int)0x80000000, (int)0xffffffff, sne , (int)0x1);
test_normal((int)0x5, (int)0x2, sltu, (int)0x0);
test_normal((int)0x5, (int)0xfffffffe, sltu, (int)0x1);
test_normal((int)0xfffffffb, (int)0x2, sltu, (int)0x0);
test_normal((int)0xfffffffb, (int)0xfffffffe, sltu, (int)0x1);
test_normal((int)0x2, (int)0x5, sltu, (int)0x1);
test_normal((int)0x2, (int)0xfffffffb, sltu, (int)0x1);
test_normal((int)0xfffffffe, (int)0x5, sltu, (int)0x0);
test_normal((int)0xfffffffe, (int)0xfffffffb, sltu, (int)0x0);
test_normal((int)0x0, (int)0x5, sltu, (int)0x1);
test_normal((int)0x2, (int)0x0, sltu, (int)0x0);
test_normal((int)0x0, (int)0x0, sltu, (int)0x0);
test_normal((int)0x2, (int)0x2, sltu, (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sltu, (int)0x1);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sltu, (int)0x0);
test_normal((int)0x8fffffff, (int)0xffffffff, sltu, (int)0x1);
test_normal((int)0x80000000, (int)0xffffffff, sltu, (int)0x1);
test_normal((int)0x5, (int)0x2, sleu, (int)0x0);
test_normal((int)0x5, (int)0xfffffffe, sleu, (int)0x1);
test_normal((int)0xfffffffb, (int)0x2, sleu, (int)0x0);
test_normal((int)0xfffffffb, (int)0xfffffffe, sleu, (int)0x1);
test_normal((int)0x2, (int)0x5, sleu, (int)0x1);
test_normal((int)0x2, (int)0xfffffffb, sleu, (int)0x1);
test_normal((int)0xfffffffe, (int)0x5, sleu, (int)0x0);
test_normal((int)0xfffffffe, (int)0xfffffffb, sleu, (int)0x0);
test_normal((int)0x0, (int)0x5, sleu, (int)0x1);
test_normal((int)0x2, (int)0x0, sleu, (int)0x0);
test_normal((int)0x0, (int)0x0, sleu, (int)0x1);
test_normal((int)0x2, (int)0x2, sleu, (int)0x1);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sleu, (int)0x1);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sleu, (int)0x0);
test_normal((int)0x8fffffff, (int)0xffffffff, sleu, (int)0x1);
test_normal((int)0x80000000, (int)0xffffffff, sleu, (int)0x1);
test_normal((int)0x5, (int)0x2, sgtu, (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, sgtu, (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, sgtu, (int)0x1);
test_normal((int)0xfffffffb, (int)0xfffffffe, sgtu, (int)0x0);
test_normal((int)0x2, (int)0x5, sgtu, (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, sgtu, (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, sgtu, (int)0x1);
test_normal((int)0xfffffffe, (int)0xfffffffb, sgtu, (int)0x1);
test_normal((int)0x0, (int)0x5, sgtu, (int)0x0);
test_normal((int)0x2, (int)0x0, sgtu, (int)0x1);
test_normal((int)0x0, (int)0x0, sgtu, (int)0x0);
test_normal((int)0x2, (int)0x2, sgtu, (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sgtu, (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sgtu, (int)0x1);
test_normal((int)0x8fffffff, (int)0xffffffff, sgtu, (int)0x0);
test_normal((int)0x80000000, (int)0xffffffff, sgtu, (int)0x0);
test_normal((int)0x5, (int)0x2, sgeu, (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, sgeu, (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, sgeu, (int)0x1);
test_normal((int)0xfffffffb, (int)0xfffffffe, sgeu, (int)0x0);
test_normal((int)0x2, (int)0x5, sgeu, (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, sgeu, (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, sgeu, (int)0x1);
test_normal((int)0xfffffffe, (int)0xfffffffb, sgeu, (int)0x1);
test_normal((int)0x0, (int)0x5, sgeu, (int)0x0);
test_normal((int)0x2, (int)0x0, sgeu, (int)0x1);
test_normal((int)0x0, (int)0x0, sgeu, (int)0x1);
test_normal((int)0x2, (int)0x2, sgeu, (int)0x1);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sgeu, (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sgeu, (int)0x1);
test_normal((int)0x8fffffff, (int)0xffffffff, sgeu, (int)0x0);
test_normal((int)0x80000000, (int)0xffffffff, sgeu, (int)0x0);
test_normal((int)0x5, (int)0x2, sequ, (int)0x0);
test_normal((int)0x5, (int)0xfffffffe, sequ, (int)0x0);
test_normal((int)0xfffffffb, (int)0x2, sequ, (int)0x0);
test_normal((int)0xfffffffb, (int)0xfffffffe, sequ, (int)0x0);
test_normal((int)0x2, (int)0x5, sequ, (int)0x0);
test_normal((int)0x2, (int)0xfffffffb, sequ, (int)0x0);
test_normal((int)0xfffffffe, (int)0x5, sequ, (int)0x0);
test_normal((int)0xfffffffe, (int)0xfffffffb, sequ, (int)0x0);
test_normal((int)0x0, (int)0x5, sequ, (int)0x0);
test_normal((int)0x2, (int)0x0, sequ, (int)0x0);
test_normal((int)0x0, (int)0x0, sequ, (int)0x1);
test_normal((int)0x2, (int)0x2, sequ, (int)0x1);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sequ, (int)0x0);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sequ, (int)0x0);
test_normal((int)0x8fffffff, (int)0xffffffff, sequ, (int)0x0);
test_normal((int)0x80000000, (int)0xffffffff, sequ, (int)0x0);
test_normal((int)0x5, (int)0x2, sneu, (int)0x1);
test_normal((int)0x5, (int)0xfffffffe, sneu, (int)0x1);
test_normal((int)0xfffffffb, (int)0x2, sneu, (int)0x1);
test_normal((int)0xfffffffb, (int)0xfffffffe, sneu, (int)0x1);
test_normal((int)0x2, (int)0x5, sneu, (int)0x1);
test_normal((int)0x2, (int)0xfffffffb, sneu, (int)0x1);
test_normal((int)0xfffffffe, (int)0x5, sneu, (int)0x1);
test_normal((int)0xfffffffe, (int)0xfffffffb, sneu, (int)0x1);
test_normal((int)0x0, (int)0x5, sneu, (int)0x1);
test_normal((int)0x2, (int)0x0, sneu, (int)0x1);
test_normal((int)0x0, (int)0x0, sneu, (int)0x0);
test_normal((int)0x2, (int)0x2, sneu, (int)0x0);
test_normal((int)0x7ffffff0, (int)0x7fffffff, sneu, (int)0x1);
test_normal((int)0x7fffffff, (int)0x7ffffff0, sneu, (int)0x1);
test_normal((int)0x8fffffff, (int)0xffffffff, sneu, (int)0x1);
test_normal((int)0x80000000, (int)0xffffffff, sneu, (int)0x1);
