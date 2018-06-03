#include "3exc_mean.h"

BaseError::~BaseError()
{
}

void BaseError::Report() const
{
	// TODO: Report values
}

void bad_hmean::Report() const
{
	BaseError::Report();
}

void bad_gmean::Report() const
{
	BaseError::Report();
}
