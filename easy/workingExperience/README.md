# WORKING EXPERIENCE

### CHALLENGE DESCRIPTION:

You are building a new social platform and want to store user's work experience. You have decided to calculate the total experience of each user in years based on the time periods that they provided. Using this approach, you need to be sure that you are taking into account the overlapping time periods in order to retrieve the actual work experience in years.

For example:

```
Jan 2010-Dec 2010
Jan 2010-Dec 2010
```

Two jobs with 12 months of experience each, but actual work experience is 1 year because of the overlapping time periods. The task is to calculate the actual work experience based on the list of time intervals.

### INPUT SAMPLE:

Your program should accept a path to a filename as its first argument. Each line of the file contains a list of time periods separated by a semicolon and a single space. Each time period is represented as the begin date and the end date. Each date consists of a month as an abbreviated name and a year with century as a decimal number separated by a single space. The begin date and the end date are separated by a hyphen.

For example:

```
Feb 2004-Dec 2009; Sep 2004-Jul 2008
Aug 2013-Mar 2014; Apr 2013-Aug 2013; Jun 2014-Aug 2015; Apr 2003
-Nov 2004; Apr 2014-Jan 2015
Mar 2003-Jul 2003; Nov 2003-Jan 2004; Apr 1999-Nov 1999
Apr 1992-Dec 1993; Feb 1996-Sep 1997; Jan 2002-Jun 2002; Sep 2003
-Apr 2004; Feb 2010-Nov 2011
Feb 2004-May 2004; Jun 2004-Jul 2004
```

### OUTPUT SAMPLE:

Print out the actual work experience in years for each test case.

For example:

```
5
4
1
6
0
```

### CONSTRAINTS:

1. The number of lines in a file is in a range from 20 to 40.
2. The dates are in a range from Jan 1990 to Dec 2020.
3. The end date is greater than the begin date.
4. The begin date is the first day of a given month, and the end date is the last day of a given month.