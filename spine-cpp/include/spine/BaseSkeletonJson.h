/*******************************************************************************
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

#ifndef SPINE_BASESKELETONJSON_H_
#define SPINE_BASESKELETONJSON_H_

#include <istream>

namespace spine {

class BaseAttachmentLoader;
class SkeletonData;
class Animation;

class BaseSkeletonJson {
public:
	BaseAttachmentLoader *attachmentLoader;
	float scale;
	bool yDown;

	/** The BaseSkeletonJson owns the attachmentLoader. */
	BaseSkeletonJson (BaseAttachmentLoader *attachmentLoader);
	virtual ~BaseSkeletonJson ();

	SkeletonData* readSkeletonData (std::ifstream &file) const;
	SkeletonData* readSkeletonData (std::istream &file) const;
	SkeletonData* readSkeletonData (const std::string &json) const;
	SkeletonData* readSkeletonData (const char *begin, const char *end) const;

	Animation* readAnimation (std::ifstream &file, const SkeletonData *skeletonData) const;
	Animation* readAnimation (std::istream &file, const SkeletonData *skeletonData) const;
	Animation* readAnimation (const std::string &json, const SkeletonData *skeletonData) const;
	Animation* readAnimation (const char *begin, const char *end, const SkeletonData *skeletonData) const;
};

} /* namespace spine */
#endif /* SPINE_BASESKELETONJSON_H_ */
