/*******************************************************
 * Copyright (c) 2016, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

// This file contains platform agnostic utility functions

#pragma once

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include <iostream>
#include <string>
#include <vector>

namespace forge {
namespace common {

/* clamp the float to [0-1] range
 *
 * @pValue is the value to be clamped
 */
float clampTo01(const float pValue);

#if defined(OS_WIN)
/* Get the paths to font files in Windows system directory
 *
 * @pFiles is the output vector to which font file paths are appended to.
 * @pDir is the directory from which font files are looked up
 * @pExt is the target font file extension we are looking for.
 */
void getFontFilePaths(std::vector<std::string>& pFiles, const std::string& pDir,
                      const std::string& pExt);
#endif

std::string clipPath(std::string path, std::string str);

std::string getEnvVar(const std::string& key);

/* Convert float value to string with given precision
 *
 * @pVal is the float value whose string representation is requested.
 * @pFormat is the c-style printf format for floats
 *
 * @return is the string representation of input float value.
 */
std::string toString(const float pVal, const std::string pFormat);

/* Print glm::mat4 to std::cout stream */
std::ostream& operator<<(std::ostream&, const glm::mat4&);

/* get the point of the surface of track ball */
glm::vec3 trackballPoint(const float pX, const float pY, const float pWidth,
                         const float pHeight);

}  // namespace common
}  // namespace forge
