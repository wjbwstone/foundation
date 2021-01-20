﻿#ifndef _LIBCOMMON_TIME_2020_05_03_10_50_22_H
#define _LIBCOMMON_TIME_2020_05_03_10_50_22_H

#include <helper/Types.h>

/*******************************************************************
*@brief  : 时间单位默认为秒，特别说明的除外
*1> std::tm 类型变量值勿使用gmtime获取
*2> UTC时间是世界时间，加上时区为本地时间
*3> unix时间戳是UTC时间1970年01月01日 0:00:00开始到当前UTC时间之间的秒数
*4> 1s = 1000ms = 1000,000us = 1000,000,000ns
********************************************************************/

namespace ws {

class Time {
public:
	Time();
	explicit Time(i64 unixTime = now());
	~Time();

public:
	i64 seconds() const;
	i64 milliSeconds() const;
	i64 microSeconds() const;
	void reset(i64 unixTime = now());

public:
	static i64 now();
	static i64 millisecond();
	static i64 microsecond();
	static i32 localTimeBias();

	/*******************************************************************
	*@brief  : unix时间戳转换为本地时间, tm存储的是1900年之后的本地时间
	********************************************************************/
	static std::tm toTmLocalTime(i64 val = now());
	static SYSTEMTIME toSystemLocalTime(i64 val = now());
	
	/*******************************************************************
	*@brief  : 将本地时间转换为unix时间戳,参数时间都是本地时间
	* tm存储的是1900年之后的本地时间
	********************************************************************/
	static i64 toUnixTime(const std::tm& tms);
	static i64 toUnixTime(const FILETIME& ft);
	static i64 toUnixTime(const SYSTEMTIME& st);
	
	/*******************************************************************
	*@brief  : 标准的本地时间格式转换为unix时间戳(支持0X) xxxx-xx-x x:xx:x
	********************************************************************/
	static i64 toUnixTime(const ustring& strtime);
	
	/*******************************************************************
	*@brief  : 返回标准的本地时间格式 xxxx-xx-xx xx:xx:xx
	********************************************************************/
	static ustring toDatetimeString(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回标准的本地日期格式 xxxx-xx-xx
	********************************************************************/
	static ustring toDateString(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回标准的本地时间格式 xx:xx:xx
	********************************************************************/
	static ustring toTimeString(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回当天开始的unix时间戳
	********************************************************************/
	static i64 toDayStartTime(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回本地时间当天走过的秒数
	********************************************************************/
	static u32 toDayPastTime(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回本周开始时间[1-7]
	********************************************************************/
	static u64 toWeekStartTime(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回当天星期天数[1-7]
	********************************************************************/
	static u32 toWeek(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回秒时间的分单位
	********************************************************************/
	static i64 toMinutes(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回该时间经过的天数
	********************************************************************/
	static u32 toDays(i64 val = now());
	
	/*******************************************************************
	*@brief  : 返回本月开始时间，unix时间戳
	********************************************************************/
	static u64 toMonthStartTime(i64 val = now());

private:
	i64 _unixTime;
};

} //ws

#endif //_LIBCOMMON_TIME_2020_05_03_10_50_22_H