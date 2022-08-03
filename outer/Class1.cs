using Data.Context;
using Domain.Models;
using IoC;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Design;
using Microsoft.Extensions.DependencyInjection;

namespace outer
{
    public class Class1
    {

    }
    public class BloggingContextFactory : IDesignTimeDbContextFactory<ReaderDBContext>
    {
        public ReaderDBContext CreateDbContext(string[] args)
        {

            var optionsBuilder = new DbContextOptionsBuilder<ReaderDBContext>();
            IServiceCollection s = new ServiceCollection();
            DependencyContainer.RegisterServices(s);
            optionsBuilder.UseApplicationServiceProvider(s.BuildServiceProvider());
            return new ReaderDBContext(optionsBuilder.Options);
        }
    }
}