//
//  OEXCourse.h
//  edXVideoLocker
//
//  Created by Rahul Varma on 05/06/14.
//  Copyright (c) 2014-2015 edX. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CourseMediaInfo;
@class OEXLatestUpdates;
@class OEXCoursewareAccess;

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, OEXStartType) {
    OEXStartTypeString,
    OEXStartTypeTimestamp,
    OEXStartTypeNone
};

NSString* NSStringForOEXStartType(OEXStartType type);
OEXStartType OEXStartTypeForString(NSString* type);

@interface OEXCourseStartDisplayInfo : NSObject

- (id)initWithDate:(nullable NSDate*)date displayDate:(nullable NSString*)displayDate type:(OEXStartType)type;

@property (readonly, nonatomic, strong, nullable) NSDate* date;
@property (readonly, copy, nonatomic, nullable) NSString* displayDate;
@property (readonly, assign, nonatomic) OEXStartType type;

@property (readonly, nonatomic) NSDictionary<NSString*, id>* jsonFields;

@end

@interface OEXCourse : NSObject

- (id)initWithDictionary:(NSDictionary*)info;
// TODO: Rename these to CamelCase (MK - eh just make this swift)
@property (readonly, nonatomic, strong, nullable) OEXLatestUpdates* latest_updates;
@property (readonly, nonatomic, strong, nullable) NSDate* end;
@property (readonly, nonatomic, strong) OEXCourseStartDisplayInfo* start_display_info;
@property (readonly, nonatomic, copy, nullable) NSString* name;
@property (readonly, nonatomic, copy, nullable) NSString* org;
@property (readonly, nonatomic, copy, nullable) NSString* video_outline;
@property (readonly, nonatomic, copy, nullable) NSString* effort;
@property (readonly, nonatomic, copy, nullable) NSString* course_id;
@property (readonly, nonatomic, copy, nullable) NSString* root_block_usage_key;
@property (readonly, nonatomic, copy, nullable) NSString* subscription_id;
@property (readonly, nonatomic, copy, nullable) NSString* number;
@property (readonly, nonatomic, copy, nullable) NSString* overview_html;
@property (readonly, nonatomic, copy, nullable) NSString* short_description;
@property (readonly, nonatomic, copy, nullable) NSString* course_updates;         //  ANNOUNCEMENTS URL
@property (readonly, nonatomic, copy, nullable) NSString* course_handouts;        //  HANDOUTS URL
@property (readonly, nonatomic, copy, nullable) NSString* course_about;           // COURSE INFO URL
@property (readonly, nonatomic, strong, nullable) OEXCoursewareAccess* courseware_access;
@property (readonly, nonatomic, copy, nullable) NSString* discussionUrl;
@property (readonly, nonatomic, copy, nullable) NSDictionary<NSString*, CourseMediaInfo*>* mediaInfo;
@property (readonly, nonatomic, strong, nullable) CourseMediaInfo* courseImageMediaInfo;
@property (readonly, nonatomic, strong, nullable) CourseMediaInfo* courseVideoMediaInfo;

@property (readonly, nonatomic, assign) BOOL isStartDateOld;
@property (readonly, nonatomic, assign) BOOL isEndDateOld;

@property (readonly, nonatomic, strong, nullable) NSString* courseImageURL;


@end


NS_ASSUME_NONNULL_END

