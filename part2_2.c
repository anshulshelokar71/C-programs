#include<stdio.h>

typedef struct bhai{
	char c;
	struct bhai *a;
}bhai;

int main(){
	bhai *p, *q, *r;
	bhai l, m, n;
	
	p = &l;
	p->c = "w";
	p->a = &m;
	q = p->a;
	
	q->c = "x";
	q->a = &n;
	r = q->a;
	
	r->c = "y";
	r->a = p;
	
	q = r = NULL;
	return;
}
