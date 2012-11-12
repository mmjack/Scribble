#ifndef _STATEMENT_DEF_H_
#define _STATEMENT_DEF_H_

class Value;

class Statement {
private:
public:
	Statement() {}
	virtual ~Statement() {}
	virtual Value Execute() = 0;
};

#endif //_STATEMENT_DEF_H_
