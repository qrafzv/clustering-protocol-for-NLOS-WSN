//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/pso_HC/PSO_HC.msg.
//

#ifndef _PSO_HC_M_H_
#define _PSO_HC_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include "RoutingPacket_m.h"
// }}

/**
 * Struct generated from src/node/communication/routing/pso_HC/PSO_HC.msg:8 by nedtool.
 */
struct nodeData7
{
    nodeData7();
    int id;
    int serialNo;
    double energy;
};

void doPacking(cCommBuffer *b, nodeData7& a);
void doUnpacking(cCommBuffer *b, nodeData7& a);

/**
 * Enum generated from <tt>src/node/communication/routing/pso_HC/PSO_HC.msg:15</tt> by nedtool.
 * <pre>
 * enum PSO_HC_Packet_Type
 * {
 * 
 *     PSO_HC_DATA_PACKET = 1;
 *     PSO_HC_FIND_NEIGHBOURS_PACKET = 2;
 * }
 * </pre>
 */
enum PSO_HC_Packet_Type {
    PSO_HC_DATA_PACKET = 1,
    PSO_HC_FIND_NEIGHBOURS_PACKET = 2
};

/**
 * Class generated from <tt>src/node/communication/routing/pso_HC/PSO_HC.msg:21</tt> by nedtool.
 * <pre>
 * packet PSO_HC_Packet extends RoutingPacket
 * {
 *     nodeData7 info;
 *     int numOfPackets = 1;
 *     int PSO_HC_PacketKind @enum(PSO_HC_Packet_Type);
 *     int schedule[];
 * }
 * </pre>
 */
class PSO_HC_Packet : public ::RoutingPacket
{
  protected:
    nodeData7 info_var;
    int numOfPackets_var;
    int PSO_HC_PacketKind_var;
    int *schedule_var; // array ptr
    unsigned int schedule_arraysize;

  private:
    void copy(const PSO_HC_Packet& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PSO_HC_Packet&);

  public:
    PSO_HC_Packet(const char *name=NULL, int kind=0);
    PSO_HC_Packet(const PSO_HC_Packet& other);
    virtual ~PSO_HC_Packet();
    PSO_HC_Packet& operator=(const PSO_HC_Packet& other);
    virtual PSO_HC_Packet *dup() const {return new PSO_HC_Packet(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual nodeData7& getInfo();
    virtual const nodeData7& getInfo() const {return const_cast<PSO_HC_Packet*>(this)->getInfo();}
    virtual void setInfo(const nodeData7& info);
    virtual int getNumOfPackets() const;
    virtual void setNumOfPackets(int numOfPackets);
    virtual int getPSO_HC_PacketKind() const;
    virtual void setPSO_HC_PacketKind(int PSO_HC_PacketKind);
    virtual void setScheduleArraySize(unsigned int size);
    virtual unsigned int getScheduleArraySize() const;
    virtual int getSchedule(unsigned int k) const;
    virtual void setSchedule(unsigned int k, int schedule);
};

inline void doPacking(cCommBuffer *b, PSO_HC_Packet& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PSO_HC_Packet& obj) {obj.parsimUnpack(b);}


#endif // ifndef _PSO_HC_M_H_

