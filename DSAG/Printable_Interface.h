/// @file Printable.h
/// @author RZN

#ifndef _PRINTABLE_INTERFACE_H
#define _PRINTABLE_INTERFACE_H

/// @class IPrintable
/// @short ������ ��� ���
class IPrintable abstract
{
public:
    /// @short �ڷᱸ���� ��� �����͸� ����Ѵ�.
    virtual void print_ds() const abstract;
};

#endif // !_PRINTABLE_H

