/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 * $Id: SrvOptServerUnicast.cpp,v 1.4 2008-08-29 00:07:37 thomson Exp $
 *
 * $Log: SrvOptServerUnicast.cpp,v $
 * Revision 1.4  2008-08-29 00:07:37  thomson
 * Temporary license change(GPLv2 or later -> GPLv2 only)
 *
 * Revision 1.3  2004-10-25 20:45:54  thomson
 * Option support, parsers rewritten. ClntIfaceMgr now handles options.
 *
 * Revision 1.2  2004/09/05 15:27:49  thomson
 * Data receive switched from recvfrom to recvmsg, unicast partially supported.
 *
 *
 */

#include "SrvOptServerUnicast.h"

TSrvOptServerUnicast::TSrvOptServerUnicast( char * buf,  int n, TMsg* parent)
	:TOptAddr(OPTION_UNICAST, buf,n, parent)
{

}

TSrvOptServerUnicast::TSrvOptServerUnicast(SmartPtr<TIPv6Addr> addr, TMsg* parent) 
    :TOptAddr(OPTION_UNICAST, addr, parent) {

}

bool TSrvOptServerUnicast::doDuties()
{
    return true;
}
