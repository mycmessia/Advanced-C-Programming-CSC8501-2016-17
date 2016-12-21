class A
{
	virtual void foo ();
	void bar ();
};

class B : A
{
	void foo () const;

	void bar ();
};

void main ()
{
}