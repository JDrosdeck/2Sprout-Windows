require 'sprout'

def get2sproutData()
  print "Starting Feed:\n"
  while 1
  s = Sprout.getSproutItem()
  print s + "\n"
  end
end


t1 = Thread.new{get2sproutData()}

t1.join()