// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (  0, uint256("0xff3c710bf19a8d7d00b4436a8923016c542c58f5ab339cd612cbf00d52470561"))
		(  10000, uint256("0x1af15516a9c3a05fb439cc54adbd9904bf11497f4da7507dbd19f62d824d91e2"))
        (  20000, uint256("0xfb1edd2ee6f4e9b3c68d72e46df458f2ff862a5ff9714c7a3b08b1607a8ac6ba"))
        (  30000, uint256("0x6e342b9052bb076210ad81733c1720f1e0f25c82cbc22648cffc54325070a51b"))
        (  40000, uint256("0xe026e1f816cb07f9bca463c5db37ea246cab45e15d533aa60fd5f7a9dd77f6dc"))
        (  50000, uint256("0xa88881f495a0c2970b5abd5655616ba71c371698d8b1943f16ea5872065ad4bd"))
        (  60000, uint256("0xf2702ae7497ad9b5df93d1b9ade6560d56c9451b69bc07510c4861c3b2ad89d7"))
        (  70000, uint256("0x52a50c666199eeae9de4220ca1411e9a8c3d7463058b210b30d73ac605089508"))
        (  80000, uint256("0x9a17868b6e65c6454d7356119fbc675af63e9dca7e679075fc6c99e68bf0e2a9"))
        (  90000, uint256("0xc75a95644eeaca1b6233e91af4527b841ce80173b3a5b454e9abfdb91cae222b"))
        (  100000, uint256("0x95714bb047abc4349658e7ac55a2ec34fc22aa453f0eb1a8a7d970beb30a76cd"))
        (  110000, uint256("0x4bbfeee9d804f8eb2c3eeebdf0188f34defb97ba9b3f8f9cd384ba8792937815"))
        (  120000, uint256("0xc4b474c1682e5e4aff2fa07a3091229d07e59a0da28bad8ecffa9e147e21d8d1"))
        (  130000, uint256("0x86a6fa8debba33f448a5ed0222fb00e85e19cda442258d79326270897f0e4802"))
        (  140000, uint256("0x0bee08e5a78147129989cd859fc6fc01ddfe0b581782bb5c8eb709df99d3408b"))
        (  150000, uint256("0x92f686c632887470fa8a40b598f24654bc7926a6ab6911e8091378098bf59c28"))
        (  160000, uint256("0x27b7c5fc141dd464568546ed770c13ed8e8d2184d63d29a937a57126a19c552d"))
        ;
    static const CCheckpointData data = {
        &mapCheckpoints,
        1554480946, // * UNIX timestamp of last checkpoint block
        160017,    // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        1.0     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        (   0, uint256("0xc9b7c4559b9f02d04ddcaf6f80b9df35e600734e66930d9c041e4823527d78ee"))
        (   10000, uint256("0x1af15516a9c3a05fb439cc54adbd9904bf11497f4da7507dbd19f62d824d91e2"))
        (   20000, uint256("0xfb1edd2ee6f4e9b3c68d72e46df458f2ff862a5ff9714c7a3b08b1607a8ac6ba"))
        (   30000, uint256("0x6e342b9052bb076210ad81733c1720f1e0f25c82cbc22648cffc54325070a51b"))
        (   40000, uint256("0xe026e1f816cb07f9bca463c5db37ea246cab45e15d533aa60fd5f7a9dd77f6dc"))
        (   50000, uint256("0xa88881f495a0c2970b5abd5655616ba71c371698d8b1943f16ea5872065ad4bd"))
        (   60000, uint256("0xf2702ae7497ad9b5df93d1b9ade6560d56c9451b69bc07510c4861c3b2ad89d7"))
        (   70000, uint256("0x52a50c666199eeae9de4220ca1411e9a8c3d7463058b210b30d73ac605089508"))
        (   80000, uint256("0x9a17868b6e65c6454d7356119fbc675af63e9dca7e679075fc6c99e68bf0e2a9"))
        (   90000, uint256("0xc75a95644eeaca1b6233e91af4527b841ce80173b3a5b454e9abfdb91cae222b"))
        (   100000, uint256("0x95714bb047abc4349658e7ac55a2ec34fc22aa453f0eb1a8a7d970beb30a76cd"))
        (   110000, uint256("0x4bbfeee9d804f8eb2c3eeebdf0188f34defb97ba9b3f8f9cd384ba8792937815"))
        (   120000, uint256("0xc4b474c1682e5e4aff2fa07a3091229d07e59a0da28bad8ecffa9e147e21d8d1"))
        (   130000, uint256("0x86a6fa8debba33f448a5ed0222fb00e85e19cda442258d79326270897f0e4802"))
        (   140000, uint256("0x0bee08e5a78147129989cd859fc6fc01ddfe0b581782bb5c8eb709df99d3408b"))
        (   150000, uint256("0x92f686c632887470fa8a40b598f24654bc7926a6ab6911e8091378098bf59c28"))
        (   154767, uint256("0x604616c69e58008ad62b36f131dff8c6d2d9a3516de60f0c2877fa9ea6924ab2"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1521658424,
        0,
        1
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
