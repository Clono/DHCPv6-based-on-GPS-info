/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 * $Id: RelTransMgr.h,v 1.3 2008-08-29 00:07:33 thomson Exp $
 *
 * $Log: RelTransMgr.h,v $
 * Revision 1.3  2008-08-29 00:07:33  thomson
 * Temporary license change(GPLv2 or later -> GPLv2 only)
 *
 * Revision 1.2  2005-01-13 22:45:55  thomson
 * Relays implemented.
 *
 * Revision 1.1  2005/01/11 22:53:36  thomson
 * Relay skeleton implemented.
 *
 *
 */

class TRelTransMgr;
#ifndef RELTRANSMGR_H
#define RELTRANSMGR_H

#include <iostream>
#include "RelCommon.h"
#include "SmartPtr.h"
#include "RelCfgIface.h"
#include "RelMsg.h"

using namespace std;

class TRelTransMgr
{
    friend ostream & operator<<(ostream &strum, TRelTransMgr &x);
  public:
    TRelTransMgr(TCtx * ctx, string xmlFile);
    ~TRelTransMgr();

    bool openSocket(SmartPtr<TRelCfgIface> confIface);

    bool doDuties();

    void relayMsg(SmartPtr<TRelMsg> msg);
    void relayMsgRepl(SmartPtr<TRelMsg> msg);
    void dump();

    bool isDone();
    void shutdown();
    
    char * getCtrlAddr();
    int    getCtrlIface();
    
  private:
    TCtx * Ctx;
    string XmlFile;
    bool IsDone;

    int ctrlIface;
    char ctrlAddr[48];
};



#endif


