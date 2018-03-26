/**
* @file       Params.cpp
*
* @brief      Parameter class for Zerocoin.
*
**/
#include "Zerocoin.h"

namespace libzerocoin {

    Params::Params(Bignum N, uint32_t securityLevel) {
        this->zkp_hash_len = securityLevel;
        this->zkp_iterations = securityLevel;

        this->accumulatorParams.k_prime = ACCPROOF_KPRIME;
        this->accumulatorParams.k_dprime = ACCPROOF_KDPRIME;

        // Generate the parameters
        CalculateParams(*this, N, ZEROCOIN_PROTOCOL_VERSION, securityLevel);

        this->accumulatorParams.initialized = true;
        this->initialized = true;
    }

    AccumulatorAndProofParams::AccumulatorAndProofParams() {
        this->initialized = false;
    }

    IntegerGroupParams::IntegerGroupParams() {
        this->initialized = false;
    }

    Bignum IntegerGroupParams::randomElement() const {
        // The generator of the group raised
        // to a random number less than the order of the group
        // provides us with a uniformly distributed random number.
        return this->g.pow_mod(Bignum::randBignum(this->groupOrder),this->modulus);
    }

} /* namespace libzerocoin */