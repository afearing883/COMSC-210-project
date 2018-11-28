const unsigned C = 581869333; // some prime number
unsigned int hash_M(unsigned n, unsigned m)

{
	unsigned shift = (32 - m) / 2;
	return((C*n) >> shift)&((1 << m) - 1);//(1 shifted left by m) (-1 flips all the bits except the most significant)
}