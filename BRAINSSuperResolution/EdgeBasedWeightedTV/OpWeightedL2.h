#ifndef OpWeightedL2_h_H
#define OpWeightedL2_h_H
#include "SRTypes.h"


extern sitk::Image SimpleOpWeightedL2(sitk::Image & norm01_lowres, sitk::Image & edgemask);

extern FloatImageType::Pointer OpWeightedL2(FloatImageType::Pointer norm01_lowres, FloatImageType::Pointer edgemask);
#endif // OpWeightedL2_h_H
