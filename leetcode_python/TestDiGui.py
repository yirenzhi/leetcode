class TestDiGui(object):
    def DiGui(self,m):
        m-=1
        if(m>0):
            self.DiGui(m)


if __name__=='__main__':
    TestDiGui().DiGui(5)
