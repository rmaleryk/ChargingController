#pragma once

class IRepository
{
public:
	virtual void queryExecute(char* query) = 0;

};