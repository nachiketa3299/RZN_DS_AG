/// @file Printable.h
/// @author RZN

#ifndef _PRINTABLE_INTERFACE_H
#define _PRINTABLE_INTERFACE_H

/// @class IPrintable
/// @short 데이터 출력 담당
class IPrintable abstract
{
public:
    /// @short 자료구조의 모든 데이터를 출력한다.
    virtual void print_ds() const abstract;
};

#endif // !_PRINTABLE_H

