/// @file DSAG.h
/// @author RZN

#include "DSAG_Interface.h"
#include "Printable_Interface.h"

#ifndef _DSAG_H
#define _DSAG_H

/// @class RDSAG
/// @short ��� �ڷᱸ���� �θ�
class RDSAG abstract:
    public IDSAG,
    public IPrintable
{ 
public:    /* CONSTRUCTORS */
    RDSAG() {};
    virtual ~RDSAG() {};
public:    /* INTERFACE IPrintable */
    virtual void print_ds() const {};
};

#endif // !_DSAG_H

