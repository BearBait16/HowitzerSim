/***********************************************************************
 * Header File:
 *    TEST HOWITZER
 * Author:
 *    Team Jackal
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/


#pragma once

#include "howitzer.h"
#include "unitTest.h"

 /*******************************
  * TEST HOWITZER
  * A friend class for Howitzer which contains the Howitzer unit tests
  ********************************/
class TestHowitzer : public UnitTest
{
public:
   void run()
   {
      // Ticket 1: Getters
      defaultConstructor();
      getPosition_zero();
      getPosition_middle();
      getMuzzleVelocity_slow();
      getMuzzleVelocity_standard();
      getElevation_up();
      getElevation_right();
      getElevation_left();

      // Ticket 2: Setters
      generatePosition_small();
      generatePosition_large();
      raise_rightDown();
      raise_rightUp();
      raise_leftDown();
      raise_leftUp();
      rotate_clock();
      rotate_counterClock();
      rotate_wrapClock();
      rotate_wrapCounterClock();

      report("Howitzer");
   }

private:
   double metersFromPixels = -1.0;

   /*****************************************************************
    *****************************************************************
    * CONSTRUCTOR
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zeros (except angle is at 45 degrees,
     *                 and the muzzle velocity is correct)
     *********************************************/
   void defaultConstructor()
   {
      //no setup required

      //excersize
      Howitzer h;

      //verify
      assertEquals(h.muzzleVelocity, 827.00);
      assertEquals(h.elevation.getDegrees(), 45.0);
      assertEquals(h.position.getX(), 0.0);
      assertEquals(h.position.getY(), 0.0);
   }//teardown

   /*****************************************************************
    *****************************************************************
    * GETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GET POSITION ZERO
     * input:   h.pos=(0,0)
     * output:  pos=(0,0)
     *********************************************/
   void getPosition_zero()
   {
      //setup
      Howitzer h;

      //excersize
      Position pos = h.getPosition();

      assertEquals(pos.getX(), 0.0);
      assertEquals(pos.getY(), 0.0);
   }//teardown

   /*********************************************
    * name:    GET POSITION MIDDLE
     * input:   h.pos=(123.4, 567.8)
     * output:  pos=(123.4, 567.8)
    *********************************************/
   void getPosition_middle()
   {
      //setup
      Howitzer h(123.4, 567.8);

      //excersize
      Position pos = h.getPosition();

      //verification
      assertEquals(pos.getX(), 123.4);
      assertEquals(pos.getY(), 567.8);

   }//teardown

   /*********************************************
    * name:    GET MUZZLE VELOCITY - SLOW SPEED
     * input:   h.muzzleVelocity=(24.68)
     * output:  m=24.68
    *********************************************/
   void getMuzzleVelocity_slow()
   {
      //setup
      Howitzer h;
      h.muzzleVelocity = 24.68;

      //excersize
      double muz = h.getMuzzleVelocity();

      //verify
      assertEquals(muz, 24.68);
   }//teardown

   /*********************************************
    * name:    GET MUZZLE VELOCITY - STANDARD SPEED
     * input:   h.muzzleVelocity=(827.00)
     * output:  m=827
    *********************************************/
   void getMuzzleVelocity_standard()
   {
      //setup
      Howitzer h;

      //excersize
      double muz = h.getMuzzleVelocity();

      //verify
      assertEquals(muz, 827.0);
   }//teardown

   /*********************************************
    * name:    GET ELEVATION - up
     * input:   h.elevation=0
     * output:  e=0
    *********************************************/
   void getElevation_up()
   {
      //setup
      Howitzer h;
      h.elevation = 0.0;

      //excersize
      Angle ele = h.getElevation();

      //verify
      assertEquals(ele.getDegrees(), 0.0);

   }//teardown

   /*********************************************
    * name:    GET ELEVATION - right
     * input:   h.elevation=0.4
     * output:  e=0.4
    *********************************************/
   void getElevation_right()
   {
      //setup
      Howitzer h;
      h.elevation = 0.4;

      //excersize
      Angle ele = h.getElevation();

      //verify
      assertEquals(ele.getDegrees(), 0.4);

   }//teardown

   /*********************************************
    * name:    GET ELEVATION - left
     * input:   h.elevation=5.8
     * output:  e=5.8
    *********************************************/
   void getElevation_left()
   {
      //setup
      Howitzer h;
      h.elevation = 0.0;

      //excersize
      Angle ele = h.getElevation();

      //verify
      assertEquals(ele.getDegrees(), 0.0);

   }//teardown

   /*****************************************************************
    *****************************************************************
    * SETTERS
    *****************************************************************
    *****************************************************************/

    /*********************************************
     * name:    GENERATE POSITION small board
     * input:   (10px, 10px)
     * output:  1px <= x <= 9px
     *********************************************/
   void generatePosition_small()
   {
      //setup
      Howitzer h;
      Position posUpperRight(10, 10);

      //excersize
      h.generatePosition(posUpperRight);
      double x = posUpperRight.getPixelsX();
      //verify
      assertEquals(x, x >= 1 && x <= 9);
   }

   /*********************************************
   * name:    GENERATE POSITION large board
   * input:   (1000px, 1000px)
   * output:  100px <= x <= 900px
   *********************************************/
   void generatePosition_large()
   {
      //setup
      Howitzer h;
      Position posUpperRight(1000, 1000);

      //excersize
      h.generatePosition(posUpperRight);
      double x = posUpperRight.getPixelsX();
      //verify
      assertEquals(x, x >= 100 && x <= 900);
   }

   /*********************************************
    * name:    RAISE to the right/down
    * input:   h.elevation=0.5radians  raise(-0.1)
    * output:  h.elevation=0.6radians
    *********************************************/
   void raise_rightDown()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(0.5);

      //excersize
      h.raise(-0.1);

      //verify
      assertEquals(h.elevation.getRadians(), 0.6);
   }

   /*********************************************
    * name:    RAISE to the right/up
    * input:   h.elevation=0.5radians  raise(0.1)
    * output:  h.elevation=0.4radians
    *********************************************/
   void raise_rightUp()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(0.5);

      //excersize
      h.raise(0.1);

      //verify
      assertEquals(h.elevation.getRadians(), 0.4);
   }

   /*********************************************
    * name:    RAISE to the left down
    * input:   h.elevation=-0.5radians  raise(-0.1)
    * output:  h.elevation=-0.6radians
    *********************************************/
   void raise_leftDown()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(-0.5);

      //excersize
      h.raise(-0.1);

      //verify
      assertEquals(h.elevation.getRadians(), -0.6);
   }

   /*********************************************
    * name:    RAISE to the left up
    * input:   h.elevation=-0.5radians  raise(0.1)
    * output:  h.elevation=0.4radians
    *********************************************/
   void raise_leftUp()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(-0.5);

      //excersize
      h.raise(0.1);

      //verify
      assertEquals(h.elevation.getRadians(), 0.4);
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=.3
    * output:  h.elevation=1.53
    *********************************************/
   void rotate_clock()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(1.23);

      //excersize
      h.raise(0.3);

      //verify
      assertEquals(h.elevation.getRadians(), 1.53);
   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE no wrapping
    * input:   h.elevation=1.23 rotate=-.3
    * output:  h.elevation=0.93
    *********************************************/
   void rotate_counterClock()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(1.23);

      //excersize
      h.raise(-0.3);

      //verify
      assertEquals(h.elevation.getRadians(), 0.93);
   }

   /*********************************************
    * name:    ROTATE CLOCKWISE CLOCKWISE WRAP BY 2PI
    * input:   h.elevation=6.1 (2pi + -0.1) rotate=.2
    * output:  h.elevation=.1
    *********************************************/
   void rotate_wrapClock()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(6.1);

      //excersize
      h.raise(0.2);

      //verify
      assertEquals(h.elevation.getRadians(), 0.1);
   }

   /*********************************************
    * name:    ROTATE COUNTER CLOCKWISE WRAP BY 4PI
    * input:   h.elevation=0.1 rotate=-.2 - 4PI
    * output:  h.elevation=6.1 (2pi + -0.1)
    *********************************************/
   void rotate_wrapCounterClock()
   {
      //setup
      Howitzer h;
      h.elevation.setRadians(0.1);

      //excersize
      h.raise(-0.2 - 4 * M_PI);

      //verify
      assertEquals(h.elevation.getRadians(), 6.1);
   }

   /*****************************************************************
    *****************************************************************
    * STANDARD FIXTURE
    *****************************************************************
    *****************************************************************/

    // setup standard fixture - set the zoom to 1100m per pixel
 //   void setupStandardFixture()
 //   {
 //      Position p;
 //      metersFromPixels = p.metersFromPixels;
 //      p.metersFromPixels = 1100.0;
 //   }

    // teardown the standard fixture - reset the zoom to what it was previously
 //   void teardownStandardFixture()
 //   {
 //      assert(metersFromPixels != -1.0);
 //      Position p;
 //      p.metersFromPixels = metersFromPixels;
 //   }
};
