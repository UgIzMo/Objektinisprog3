#include "pch.h"
#include "CppUnitTest.h"
#include "zmogus.h"
#include "studentas.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace v20TEST
{
    TEST_CLASS(v20TEST)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Studentas a;
            Assert::AreEqual(a.outputas(), std::string("0"));
        }

        TEST_METHOD(TestDefaultConstructor)
        {
            // Test default constructor
            Studentas a;
            Assert::AreEqual(a.getVardas(), std::string(""));
            Assert::AreEqual(a.getPavarde(), std::string(""));
            Assert::AreEqual(a.getEgzaminas(), 0);
            Assert::IsTrue(a.getNamuDarbai().empty());
        }

        TEST_METHOD(TestOperators)
        {
            Studentas f;
            Studentas expected;
            Assert::AreEqual(f.getVardas(), expected.getVardas());
            Assert::AreEqual(f.getPavarde(), expected.getPavarde());
            Assert::AreEqual(f.skaiciuotiGalutini(true), expected.skaiciuotiGalutini(true));
        }

        TEST_METHOD(TestConstructorWithParams)
        {
            // Test constructor with parameters
            Studentas b("Kamile", "Macaite");
            Assert::AreEqual(b.getVardas(), std::string("Kamile"));
            Assert::AreEqual(b.getPavarde(), std::string("Macaite"));
            Assert::AreEqual(b.getEgzaminas(), 0);
            Assert::IsTrue(b.getNamuDarbai().empty());
        }

        TEST_METHOD(TestSettersAndGetters)
        {
            // Test setters and getters
            Studentas c;
            c.setVardas("Ugne");
            c.setPavarde("Mockute");
            c.setEgzaminas(9);
            c.addNamuDarbas(8);
            c.addNamuDarbas(7);

            Assert::AreEqual(c.getVardas(), std::string("Ugne"));
            Assert::AreEqual(c.getPavarde(), std::string("Mockute"));
            Assert::AreEqual(c.getEgzaminas(), 9);
            Assert::AreEqual(c.getNamuDarbai().size(), size_t(2));
            Assert::AreEqual(c.getNamuDarbai()[0], 8);
            Assert::AreEqual(c.getNamuDarbai()[1], 7);
        }

        TEST_METHOD(TestSkaiciuotiVidurki)
        {
            // Test calculating average
            Studentas d;
            d.addNamuDarbas(8);
            d.addNamuDarbas(7);
            d.setEgzaminas(9);
            Assert::AreEqual(d.skaiciuotiVidurki(), 7.5); // (8 + 7) / 2 = 7.5
        }

        TEST_METHOD(TestSkaiciuotiMediana)
        {
            // Test calculating median
            Studentas e;
            e.addNamuDarbas(8);
            e.addNamuDarbas(7);
            e.addNamuDarbas(9);
            e.setEgzaminas(9);
            Assert::AreEqual(e.skaiciuotiMediana(), 8.0); // Median is 8
        }

        TEST_METHOD(TestRuleOfFive)
        {
            // Test Rule of Five
            // Default constructor
            Studentas f;
            Assert::AreEqual(f.getVardas(), std::string(""));
            Assert::AreEqual(f.getPavarde(), std::string(""));
            Assert::AreEqual(f.getEgzaminas(), 0);
            Assert::IsTrue(f.getNamuDarbai().empty());

            // Constructor with parameters
            Studentas g("Jonas", "Baronas");
            Assert::AreEqual(g.getVardas(), std::string("Jonas"));
            Assert::AreEqual(g.getPavarde(), std::string("Baronas"));
            Assert::AreEqual(g.getEgzaminas(), 0);
            Assert::IsTrue(g.getNamuDarbai().empty());

            // Setters and getters
            Studentas h;
            h.setVardas("Ugne");
            h.setPavarde("Mockute");
            h.setEgzaminas(9);
            h.addNamuDarbas(8);
            h.addNamuDarbas(7);

            Assert::AreEqual(h.getVardas(), std::string("Ugne"));
            Assert::AreEqual(h.getPavarde(), std::string("Mockute"));
            Assert::AreEqual(h.getEgzaminas(), 9);
            Assert::AreEqual(h.getNamuDarbai().size(), size_t(2));
            Assert::AreEqual(h.getNamuDarbai()[0], 8);
            Assert::AreEqual(h.getNamuDarbai()[1], 7);

            // Copy constructor
            Studentas original("Joana", "Morengaite");
            original.addNamuDarbas(8);
            original.addNamuDarbas(7);
            original.setEgzaminas(9);

            Studentas copy(original);

            Assert::AreEqual(copy.getVardas(), std::string("Joana"));
            Assert::AreEqual(copy.getPavarde(), std::string("Morengaite"));
            Assert::AreEqual(copy.getEgzaminas(), 9);
            Assert::AreEqual(copy.getNamuDarbai().size(), original.getNamuDarbai().size());
            for (size_t i = 0; i < original.getNamuDarbai().size(); ++i) {
                Assert::AreEqual(copy.getNamuDarbai()[i], original.getNamuDarbai()[i]);
            }

            // Assignment operator
            Studentas original2("Gustas", "Kairys");
            original2.addNamuDarbas(8);
            original2.addNamuDarbas(7);
            original2.setEgzaminas(9);

            Studentas copy2;
            copy2 = original2;

            Assert::AreEqual(copy2.getVardas(), std::string("Gustas"));
            Assert::AreEqual(copy2.getPavarde(), std::string("Kairys"));
            Assert::AreEqual(copy2.getEgzaminas(), 9);
            Assert::AreEqual(copy2.getNamuDarbai().size(), original2.getNamuDarbai().size());
            for (size_t i = 0; i < original2.getNamuDarbai().size(); ++i) {
                Assert::AreEqual(copy2.getNamuDarbai()[i], original2.getNamuDarbai()[i]);
            }

            // Move constructor
            Studentas original3("Emilija", "Birbilaite");
            original3.addNamuDarbas(8);
            original3.addNamuDarbas(7);
            original3.setEgzaminas(9);

            Studentas moved(std::move(original3));

            Assert::AreEqual(moved.getVardas(), std::string("Emilija"));
            Assert::AreEqual(moved.getPavarde(), std::string("Birbilaite"));
            Assert::AreEqual(moved.getEgzaminas(), 9);
            Assert::AreEqual(moved.getNamuDarbai().size(), size_t(2));
            Assert::AreEqual(moved.getNamuDarbai()[0], 8);
            Assert::AreEqual(moved.getNamuDarbai()[1], 7);
            Assert::IsTrue(original3.getVardas().empty());
            Assert::IsTrue(original3.getPavarde().empty());
            Assert::IsTrue(original3.getNamuDarbai().empty());
            Assert::AreEqual(original3.getEgzaminas(), 0);

            // Move assignment operator
            Studentas original4("Adomas", "Adomaitis");
            original4.addNamuDarbas(8);
            original4.addNamuDarbas(7);
            original4.setEgzaminas(9);

            Studentas moved2;
            moved2 = std::move(original4);

            Assert::AreEqual(moved2.getVardas(), std::string("Adomas"));
            Assert::AreEqual(moved2.getPavarde(), std::string("Adomaitis"));
            Assert::AreEqual(moved2.getEgzaminas(), 9);
            Assert::AreEqual(moved2.getNamuDarbai().size(), size_t(2));
            Assert::AreEqual(moved2.getNamuDarbai()[0], 8);
            Assert::AreEqual(moved2.getNamuDarbai()[1], 7);
            Assert::IsTrue(original4.getVardas().empty());
            Assert::IsTrue(original4.getPavarde().empty());
            Assert::IsTrue(original4.getNamuDarbai().empty());
            Assert::AreEqual(original4.getEgzaminas(), 0);
        }
    };
}
