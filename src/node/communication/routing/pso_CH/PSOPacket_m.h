//
// Generated file, do not edit! Created by nedtool 4.6 from src/node/communication/routing/pso_CH/PSOPacket.msg.
//

#ifndef _PSOPACKET_M_H_
#define _PSOPACKET_M_H_

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
 * Struct generated from src/node/communication/routing/pso_CH/PSOPacket.msg:8 by nedtool.
 */
struct nodeData9
{
    nodeData9();
    int id;
    int serialNo;
    double energy;
};

void doPacking(cCommBuffer *b, nodeData9& a);
void doUnpacking(cCommBuffer *b, nodeData9& a);

/**
 * Enum generated from <tt>src/node/communication/routing/pso_CH/PSOPacket.msg:15</tt> by nedtool.
 * <pre>
 * enum PSOPacket_Type
 * {
 * 
 *     PSO_ADV_PACKET = 1;
 *     PSO_JOIN_PACKET = 2;
 *     PSO_TDMA_PACKET = 3;
 *     PSO_DATA_PACKET = 4;
 *     PSO_FIND_NEIGHBOURS_PACKET = 5;
 * }
 * </pre>
 */
enum PSOPacket_Type {
    PSO_ADV_PACKET = 1,
    PSO_JOIN_PACKET = 2,
    PSO_TDMA_PACKET = 3,
    PSO_DATA_PACKET = 4,
    PSO_FIND_NEIGHBOURS_PACKET = 5
};

/**
 * Class generated from <tt>src/node/communication/routing/pso_CH/PSOPacket.msg:24</tt> by nedtool.
 * <pre>
 * packet PSOPacket extends RoutingPacket
 * {
 *     nodeData9 info;
 *     int numOfPackets;
 *     int PSOPacketKind @enum(PSOPacket_Type);
 *     int schedule[];
 * }
 * </pre>
 */
class PSOPacket : public ::RoutingPacket
{
  protected:
    nodeData9 info_var;
    int numOfPackets_var;
    int PSOPacketKind_var;
    int *schedule_var; // array ptr
    unsigned int schedule_arraysize;

  private:
    void copy(const PSOPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PSOPacket&);

  public:
    PSOPacket(const char *name=NULL, int kind=0);
    PSOPacket(const PSOPacket& other);
    virtual ~PSOPacket();
    PSOPacket& operator=(const PSOPacket& other);
    virtual PSOPacket *dup() const {return new PSOPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual nodeData9& getInfo();
    virtual const nodeData9& getInfo() const {return const_cast<PSOPacket*>(this)->getInfo();}
    virtual void setInfo(const nodeData9& info);
    virtual int getNumOfPackets() const;
    virtual void setNumOfPackets(int numOfPackets);
    virtual int getPSOPacketKind() const;
    virtual void setPSOPacketKind(int PSOPacketKind);
    virtual void setScheduleArraySize(unsigned int size);
    virtual unsigned int getScheduleArraySize() const;
    virtual int getSchedule(unsigned int k) const;
    virtual void setSchedule(unsigned int k, int schedule);
};

inline void doPacking(cCommBuffer *b, PSOPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PSOPacket& obj) {obj.parsimUnpack(b);}


#endif // ifndef _PSOPACKET_M_H_

