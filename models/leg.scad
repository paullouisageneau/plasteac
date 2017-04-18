/* 
 * Copyright (c) 2017 by Paul-Louis Ageneau
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

servo_height = 19 + 0.5;
servo_width  = 20 + 0.5;
servo_depth  =  9 + 0.5;
servo_side   =  6;
border = 3;
$fn = 32;

union() {
    difference() {
        rcube([servo_height, servo_depth, servo_width + servo_side] + [border*2+1, border*2, 2], border);
        translate([-0.5, 0, 2]) union() {
            cube([servo_height, servo_depth, servo_width + servo_side], center = true);
            translate([-servo_height/4, 0, 3-servo_width/2- 6]) cube([servo_height/2, 3.25, 3], center = true);
            translate([-1.25, 0, -servo_width/2]) cylinder(r = 3, h = 20, center = true);
            translate([0, 0, servo_width/2 - 4]) {
                translate([border+0.01, 0, servo_width/2]) cube([servo_height+border*2, servo_depth, servo_width], center = true);
                translate([servo_height/2, 0, -4]) rotate([0, 90, 0]) cylinder(r = 2.75, h = 10, center = true);
                translate([0, 0, 0]) rotate([0, 90, 0]) cylinder(r = 3, h = servo_height*2, center = true);
                translate([servo_height/2, 0, 0]) rotate([0, 90, 0]) cylinder(r = servo_depth/2, h = 10, center = true);
                translate([servo_height/2, 0, -18]) union() {
                    translate([0, 0, 0.25]) rotate([0, 90, 0]) cylinder(r = 2.5, h = 10, center = true);
                    translate([-3.75, 0, 0]) cube([7.5, servo_depth, servo_side], center = true);
                }
            }
        }
    }
    translate([servo_height/2-7.5, 0, 8 - 18]) difference() {
        cube([1.5, servo_depth, servo_side], center = true);
        translate([0, 0, 0.25]) rotate([0, 90, 0]) cylinder(r = 0.75, h = 10, center = true);
    }
}

module rcube(size, border) {
    union() {
        $fn = 30;
        cube(size = size - [0, border, 0]*2, center = true);
        cube(size = size - [border, 0, 0]*2, center = true);
        v = [size.x/2-border, size.y/2-border, size.z/2];
        translate([ v.x, v.y, 0]) cylinder(r = border, h = v.z*2, center = true);
        translate([ v.x,-v.y, 0]) cylinder(r = border, h = v.z*2, center = true);
        translate([-v.x, v.y, 0]) cylinder(r = border, h = v.z*2, center = true);
        translate([-v.x,-v.y, 0]) cylinder(r = border, h = v.z*2, center = true);
    }
}