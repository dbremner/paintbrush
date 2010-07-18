/**
 * Copyright 2007-2009 Soggy Waffles
 * 
 * This file is part of Paintbrush.
 * 
 * Paintbrush is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Paintbrush is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Paintbrush.  If not, see <http://www.gnu.org/licenses/>.
 */


#import <Cocoa/Cocoa.h>

@class SWToolboxController;
@class SWToolbox;
@class SWTool;
@class SWDocument;
@class SWImageDataSource;

@interface SWPaintView : NSView 
{
	// Have a connection to the SWDocument instance that owns this view
	IBOutlet SWDocument *document;
	
	// The data source: light of our life
	SWImageDataSource *dataSource;
	
	NSPoint currentPoint;
	NSColor *frontColor;
	NSColor *backColor;
	NSData *undoData;
	NSBezierPath *expPath;
	SWToolboxController *toolboxController;
	SWToolbox *toolbox;

	BOOL isPayingAttention;
	
	NSColor *backgroundColor;
	
	// Grid related
	BOOL showsGrid;
	CGFloat gridSpacing;
	NSColor *gridColor;
}

- (void)preparePaintViewWithDataSource:(SWImageDataSource *)ds
							   toolbox:(SWToolbox *)tb;
- (NSRect)calculateWindowBounds:(NSRect)frameRect;
- (void)setBackgroundColor:(NSColor *)color;
- (void)clearOverlay;


// Grid related
- (void)setShowsGrid:(BOOL)shouldShowGrid;
- (void)setGridSpacing:(CGFloat)spacing;
- (void)setGridColor:(NSColor *)color;
- (BOOL)showsGrid;
- (CGFloat)gridSpacing;
- (NSColor *)gridColor;
- (NSBezierPath *)gridInRect:(NSRect)rect;

@end

//void DrawGridWithSettingsInRect(CGFloat spacing, NSColor *color, NSRect rect, NSPoint gridOrigin);