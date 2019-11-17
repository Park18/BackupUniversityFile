#pragma once
#ifndef ERROR_HPP
#define ERROR_HPP

/**
 @class		Error
 @date		2019/11/17
 @author	박현우
 @details	프로그램에서 발생하는 에러를 관여하는 클래스
 */
class Error
{
public:
	void not_found();
	void index_access();
};

#endif // !ERROR_HPP

