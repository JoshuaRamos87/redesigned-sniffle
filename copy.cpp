int string_compare(char *s, char *t, int i, int j)
{
	int k;			/* counter */
	int opt[3];		/* cost of the three options */
	int lowest_cost;	/* lowest cost */

	if (i == 0) return(j * indel(' '));
	if (j == 0) return(i * indel(' '));

	opt[MATCH] = string_compare(s,t,i-1,j-1) + match(s[i],t[j]);
	opt[INSERT] = string_compare(s,t,i,j-1) + indel(t[j]);
	opt[DELETE] = string_compare(s,t,i-1,j) + indel(s[i]);

	lowest_cost = opt[MATCH];
	for (k=INSERT; k<=DELETE; k++)
		if (opt[k] < lowest_cost) lowest_cost = opt[k];

	m[i][j].cost = lowest_cost;	/* REMOVE FROM PRINTED VERSION */

	return( lowest_cost );
} 